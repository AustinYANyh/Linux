#include"USocket.hpp"

#include<sstream>

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        cout<<"start wrong"<<endl;
        return -1;
    }

    uint16_t port;
    string ip=argv[1];

    stringstream tmp;
    tmp<<argv[2];
    tmp>>port;

    Socket sock;
    CHECK_RET(sock.Sock());

    while(1)
    {
        string buf;
	cout<<"client say:";
        cin>>buf;

        sock.Send(buf,ip,port);

        buf.clear();

        sock.Recv(buf,ip,port);
        cout<<"server say:"<<buf<<endl;
    }

    sock.Close();

    return 0;
}
