/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：陆子涵
*   创建日期：
*   描    述： 
================================================================*/

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int ticket=100;

//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


pthread_mutex_t mutex;

void* getTickets(void* arg)
{
    while(1)
    {
	pthread_mutex_lock(&mutex);

	if(ticket>0)
	{
	    usleep(1000);
	    printf("bull [%d] get tickets: %d\n",(int)arg,ticket);
	    ticket--;
	}
	else
	{
	    printf("no tickets,bull[%d] exit!\n",(int)arg);

	    //需要在任意有可能退出线程的时候加锁
	    pthread_mutex_unlock(&mutex);

	    pthread_exit(NULL);
	}

	pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t tid[4];

    //int pthread_mutex_init(pthread_mutex_t *restrict mutex,
    //	                  const pthread_mutexattr_t *restrict attr);

    pthread_mutex_init(&mutex,NULL);

    int i=0;

    for(i=0;i<4;++i)
    {
	int ret=pthread_create(&tid[i],NULL,getTickets,(void*)i);
	if(ret!=0)
	{
	    printf("pthread_create error\n");
	    return -1;
	}
    }

    for(i=0;i<4;++i)
    {
	pthread_join(tid[i],NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
