/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：闫云皓
*   创建日期：
*   描    述： 
================================================================*/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>

int main()
{
    //int mkfifo(const char *pathname, mode_t mode);
    char *file1="./testfifo.fifo";
    umask(0);

    int ret1=mkfifo(file1,0664);

    if(ret1<0)
    {
	if(errno!=EEXIST)
	{
	    perror("mkfifo error");
	    return -1;
	}
    }

    int fd1=open(file1,O_RDONLY);

    if(fd1<0)
    {
	perror("open error");
	return -1;
    }

    while(1)
    {
	char buf[1024]={0};

	read(fd1,buf,1023);
	printf("陆子涵说:%s\n",buf);
    
    }

    close(fd1);
    return 0;
}
