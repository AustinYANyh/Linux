/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：闫云皓
*   创建日期：
*   描    述： 
================================================================*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<error.h>
#include<stdlib.h>
#include<string.h>
#include <sys/shm.h>

#define IPC_KEY 0x12345678

int main()
{
    //int shmget(key_t key, size_t size, int shmflg);
    int shmID=shmget(IPC_KEY,32,IPC_CREAT|0664);

    if(shmID<0)
    {
	perror("shmget error");
	return -1;
    }
    
    //void *shmat(int shmid, const void *shmaddr, int shmflg);
    void *shm_start=shmat(shmID,NULL,0);

    if(shm_start==(void*)-1)
    {
	perror("shmat error");
	return -1;
    }

    int i = 0;

    while(1) 
    {
        sprintf(shm_start, "%s-%d", "陆子涵我爱你~", i++);
        sleep(1);
    }

    //int shmdt(const void *shmaddr);
    shmdt(shm_start);

    //int shmctl(int shmid, int cmd, struct shmid_ds *buf);
    shctl(shmID,IPC_RMID,NULL);

    return 0;
}
