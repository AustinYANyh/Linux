#include<iostream>
#include<queue>
#include<pthread.h>

using namespace std;

#define MAX_QUEUE 10

class BlockQueue
{
    public:
	BlockQueue(int capacity=MAX_QUEUE):_capacity(capacity)
	{
	    pthread_mutex_init(&mutex,NULL);
	    pthread_cond_init(&product,NULL);
	    pthread_cond_init(&consumer,NULL);
	}

	~BlockQueue()
	{
	    pthread_mutex_destroy(&mutex);
	    pthread_cond_destroy(&product);
	    pthread_cond_destroy(&consumer);
	}

	void Pushdata(int data)
	{
	    pthread_mutex_lock(&mutex);
	    while(_capacity==q.size())
	    {
		pthread_cond_wait(&product,&mutex);
	    }
	    q.push(data);

	    pthread_cond_signal(&consumer);
	    pthread_mutex_unlock(&mutex);
	}

	void Popdata(int& data)
	{
	    while(q.empty())
	    {
		pthread_cond_wait(&consumer,&mutex);
	    }
	    data=q.front();
	    q.pop();

	    pthread_cond_signal(&product);
	    pthread_mutex_unlock(&mutex);
	}

    private:
	int _capacity;
	queue<int> q;
	pthread_mutex_t mutex;
	pthread_cond_t product;
	pthread_cond_t consumer;
};


void* thread_product(void* arg)
{
    BlockQueue *q=(BlockQueue*)arg;
    
    int i=0;

    while(1)
    {
	q->Pushdata(i++);
	cout<<"product put data:"<<i<<endl;
    }
    return NULL;
}

void* thread_consumer(void* arg)
{
    BlockQueue *q=(BlockQueue*)arg;
    
    int data;

    while(1)
    {
	q->Popdata(data);
	cout<<"consumer get data:"<<data<<endl;
    }
    return NULL;
}

int main()
{
    pthread_t tid1[4],tid2[4];

    BlockQueue q;

    for(int i=0;i<4;++i)
    {
	int ret=pthread_create(&tid1[i],NULL,thread_product,(void*)&q);

	if(ret!=0)
	{
	    cout<<"pthread_create error"<<endl;
	    return -1;
	}
    }

    for(int i=0;i<4;++i)
    {
	int ret=pthread_create(&tid2[i],NULL,thread_consumer,(void*)&q);

	if(ret!=0)
	{
	    cout<<"pthread_create error"<<endl;
	    return -1;
	}
    }

    for(int i=0;i<4;++i)
    {
	pthread_join(tid1[i],NULL);
    }

    for(int i=0;i<4;++i)
    {
	pthread_join(tid2[i],NULL);
    }


    return 0;
}
