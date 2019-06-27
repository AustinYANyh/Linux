#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void* DJ(void *arg)
{
    char* ptr;

    ptr="鹿宝宝不见了QAQ";

    printf("创建的线程即将被终止!\n");

    printf("倒计时，3\n");
    sleep(1);
    printf("倒计时，2\n");
    sleep(1);
    printf("倒计时，1\n");
    sleep(1);

    //void pthread_exit(void *retval);
    pthread_exit(ptr);

    while(1)
    {
	printf("i am common thread\n",(char*)arg);
	sleep(1);
    }
    return NULL;
}

int main()
{
    //pthread_t pthread_self(void);
    
    pthread_t mtid;

    mtid=pthread_self();


    //int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    //                          void *(*start_routine) (void *), void *arg);
    
    pthread_t tid;
    
    char* name="this is a DJ\n";

    int ret=pthread_create(&tid,NULL,DJ,(void*)mtid);

    if(ret!=0)
    {
	printf("pthread_create failed\n");
	return -1;
    }

    void* retval;

    pthread_join(tid, &retval);

    printf("tid:%p\n", tid);

    printf("ret:%d retval:%s\n",ret, retval);

    while(1)
    {
	printf("i am main thread\n");
	sleep(1);
    }

    return 0;
}
