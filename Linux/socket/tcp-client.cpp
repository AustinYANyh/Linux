#include"tcpsocket.hpp"
#include<iostream>

using namespace std;

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        cout<<"start wrong"<<endl;
        return -1;
    }

    TcpSocket sock;

    CHECK_RET(sock.Socket());

    CHECK_RET(sock.Connect(argv[1],argv[2]));

    while(1)
    {
        string  buf;
        cout<<"client say:";
        fflush(stdout);
        cin>>buf;

        sock.Send(buf);

        buf.clear();

        sock.Recv(buf);
        cout<<"server say:"<<buf<<endl;
    }

    sock.Close();

    return 0;
}
