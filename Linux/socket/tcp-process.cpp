#include<iostream>
#include<stdio.h>
#include<signal.h>
#include<sys/wait.h>
#include"tcpsocket.hpp"

using namespace std;

void sigcb(int signo)
{
    while(waitpid(-1,NULL,WNOHANG)>0);
}

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        cout<<"start wrong"<<endl;
        return -1;
    }

    signal(SIGCHLD,sigcb);

    TcpSocket lst_sock;

    CHECK_RET(lst_sock.Socket());

    CHECK_RET(lst_sock.Bind(argv[1],argv[2]));

    CHECK_RET(lst_sock.Listen());

    while(1)
    {
        TcpSocket clientsock;

        bool ret=lst_sock.Accept(clientsock);

        if(ret==false)
        {
            continue;
        }

        if(fork()==0)
        {
            while(1)
            {
                string buf;

                ret=clientsock.Recv(buf);

                if(ret==false)
                {
                    clientsock.Close();
                    continue;
                }
                cout<<"client say:"<<buf<<endl;

                buf.clear();

                cout<<"server say:";
                fflush(stdout);

                cin>>buf;
                clientsock.Send(buf);
            }
            clientsock.Close();
        }
        clientsock.Close();
    }

    lst_sock.Close();

    return 0;
}
