/*=============================================================== 
*   Copyright (C) . All rights reserved.")
*   文件名称： 
*   创 建 者：闫云皓
*   创建日期：
*   描    述： 
================================================================*/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sigcb(int signo)
{
    printf("signo is : %d\n",signo);
}

int main()
{
    //#include <signal.h>

    //int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);

    sigset_t set,old_set;
    sigemptyset(&set);

    //可靠信号与不可靠信号的对比
    signal(SIGINT,sigcb);
    signal(34,sigcb);

    //把所有信号都添加到set集合中
    sigfillset(&set);

    //把set集合中的所有信号都阻塞
    sigprocmask(SIG_BLOCK,&set,&old_set);

    getchar();

    sigprocmask(SIG_UNBLOCK,&set,NULL);

    return 0;
}
