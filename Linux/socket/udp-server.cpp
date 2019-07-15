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

    sock.Bind(ip,port);

    while(1)
    {
        string buf;

        sock.Recv(buf,ip,port);

	cout<<"client say:"<<buf<<endl;

        buf.clear();

	cout<<"server say:";
	cin>>buf;
        sock.Send(buf,ip,port);
    }

    sock.Close();
    
    return 0;
}
