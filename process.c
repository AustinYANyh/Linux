#include <stdio.h>
#include<unistd.h>


int main()
{
    int pid=getpid();
    pid=fork();
    while(1)
    {
	 if(pid==0)
	 {
	    printf("%d 子进程打印:被打死!~\n",getpid());
	    sleep(1);
	 }
	 else
	 {
	    printf("%d 父进程打印:打死你!~\n",getpid());
	    sleep(1);
	 }
    }
    return 0;
}
