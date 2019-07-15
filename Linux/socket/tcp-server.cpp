#include<iostream>
#include<stdio.h>
#include"tcpsocket.hpp"

using namespace std;

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
        TcpSocket clientsock;

        bool ret=lst_sock.Accept(clientsock);

        if(ret==false)
        {
            continue;
        }

        string buf;

        ret=clientsock.Recv(buf);

        if(ret==false)
        {
            clientsock.Close();
            continue;
        }
        cout<<"client say:"<<buf<<endl;

        buf.clear();

        cout<<"server say:"<<endl;
        fflush(stdout);

        cin>>buf;
        clientsock.Send(buf);
    }

    lst_sock.Close();

    return 0;
}
