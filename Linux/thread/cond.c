#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

//定义互斥锁变量和条件变量（2个）
pthread_mutex_t mutex;

pthread_cond_t eat;
pthread_cond_t cook;

//是否有食物的依据
int havefood=0;

void *eatfood(void* arg)
{
    while(1)
    {
	//判断之前先加锁
	pthread_mutex_lock(&mutex);
	//判断是否又食物必须是循环判断
	while(havefood==0)
	{
	    //顾客等待在顾客的等待队列中
	    pthread_cond_wait(&eat,&mutex);
	}
	printf("开始进食~\n");
	havefood=0;

	//把食物吃掉之后，唤醒厨师，进行解锁操作
	pthread_cond_signal(&cook);
	pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
void *cookfood(void* arg)
{
    while(1)
    {
	//判断之前先加锁，同时也是循环判断
	pthread_mutex_lock(&mutex);
	while(havefood==1)
	{
	    //有食物，不做，我刷抖音玩王者
	    pthread_cond_wait(&cook,&mutex);
	}
	//没有食物，老夫要开始做菜了~
	printf("老夫要开始做菜了~\n");
	havefood=1;

	//有了食物，可以唤醒顾客,进行解锁操作
	pthread_cond_signal(&eat);
	pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_mutex_init(&mutex,NULL);

    pthread_cond_init(&eat,NULL);

    pthread_cond_init(&cook,NULL);

    pthread_t tid1,tid2;

    int i;

    for(i=0;i<4;i++)
    {
	int ret=pthread_create(&tid1,NULL,eatfood,NULL);

	if(ret!=0)
	{
	    printf("thread create error\n");
	    return -1;
	}

    }

    for(i=0;i<4;i++)
    {
	int ret=pthread_create(&tid2,NULL,cookfood,NULL);

	if(ret!=0)
	{
	    printf("thread create error\n");
	    return -1;
	}

    }
    pthread_join(tid1,NULL);

    pthread_join(tid2,NULL);

    //解锁、销毁互斥锁、销毁条件变量
    pthread_mutex_destroy(&mutex);

    pthread_cond_destroy(&eat);

    pthread_cond_destroy(&cook);

    return 0;
}
