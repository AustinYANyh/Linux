#include<iostream>
#include<stdio.h>
#include"tcpsocket.hpp"

using namespace std;

void* thr_start(void* arg)
{   
    TcpSocket *clientsock=(TcpSocket*)arg;
    while(1)
    {
        string buf;

        clientsock->Recv(buf);

        cout<<"client say:"<<buf<<endl;

        buf.clear();

        cout<<"server say:";
        fflush(stdout);

        cin>>buf;
        clientsock->Send(buf);
    }

    clientsock->Close();
    delete clientsock;
    return NULL;

}
int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        cout<<"start wrong"<<endl;
        return -1;
    }

    TcpSocket lst_sock;

    CHECK_RET(lst_sock.Socket());

    CHECK_RET(lst_sock.Bind(argv[1],argv[2]));

    CHECK_RET(lst_sock.Listen());

    while(1)
    {
        TcpSocket *clientsock=new TcpSocket();

        bool ret=lst_sock.Accept(*clientsock);

        if(ret==false)
        {
            continue;
        }

        pthread_t tid;
        pthread_create(&tid,NULL,thr_start,(void*)clientsock);

    }

    lst_sock.Close();

    return 0;
}

