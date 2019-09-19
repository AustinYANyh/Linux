/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：闫云皓
*   创建日期：
*   描    述： 
================================================================*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<error.h>
#include<sys/stat.h>
#include<stdlib.h>

int  main()
{
    int pipefd[2];
    int ret=pipe(pipefd);

    if(ret<0)
    {
	perror("pipe error");
	return -1;
    }

    int pid1=fork();
    if(pid1==0)
    {
	close(pipefd[0]);

	dup2(pipefd[1],1);

	//int execlp(const char *file, const char *arg, ...);
	execlp("ls","ls",NULL);
	exit(0);
    }

    int pid2=fork();
    if(pid2==0)
    {
	close(pipefd[1]);

	dup2(pipefd[0],0);

	//int execlp(const char *file, const char *arg, ...);
	execlp("grep","grep","make",NULL);
	exit(0);
    }

    close(pipefd[0]);
    close(pipefd[1]);

    waitpid(pid1,NULL,0);
    waitpid(pid2,NULL,0);

    return 0;
}
