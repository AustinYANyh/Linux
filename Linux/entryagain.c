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

int x=1;
int y=1;

int sum(int* a,int* b)
{
    (*a)++;
    sleep(3);
    (*b)++;

    return (*a)+(*b);
}

void sigcb(signo)
{
    printf("signo is : %d\n",sum(&x,&y));
}

int main()
{
    signal(SIGINT,sigcb);
    printf("sum is : %d\n",sum(&x,&y));

    return 0;
}
