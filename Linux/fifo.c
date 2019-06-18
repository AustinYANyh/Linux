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
    char *file="./testfifo.fifo";

    umask(0);

    int ret=mkfifo(file,0664);
    if(ret<0)
    {
	perror("mkfifo error");
	return -1;
    }
    return 0;
}
