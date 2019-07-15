#pragma once

#include<iostream>
#include<sstream>
#include<stdio.h>
#include<string>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>

using namespace std;

#define CHECK_RET(q) if((q)==false){return -1;}

class TcpSocket
{
    public:
        void SetFd(int fd)
        {
            _sockfd=fd;
        }

        int GetFd()
        {
            return _sockfd;
        }

        bool Socket()
        {
	    //int socket(int domain, int type, int protocol);
	    _sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if(_sockfd<0)
            {
                cout<<"sock error"<<endl;
                return false;
            }
            return true;
        }

        int strtoint(const string &s)
        {
            int num;
            stringstream tmp;
            tmp<<s;
            tmp>>num;
            return num;
        }
        bool Bind(const string &ip,const string &port)
        {
            struct sockaddr_in addr;

            addr.sin_family=AF_INET;
            addr.sin_port=htons(strtoint(port));
            addr.sin_addr.s_addr=inet_addr(ip.c_str());

            socklen_t len=sizeof(struct sockaddr_in);

            int ret=bind(_sockfd,(struct sockaddr*)&addr,len);

            if(ret<0)
            {
                cout<<"bind error"<<endl;
                return false;
            }
            return true;
        }
        
        bool Listen(const int backlog=5)
        {
            //int listen(int sockfd, int backlog);
            int ret=listen(_sockfd,backlog);

            if(ret<0)
            {
                cout<<"listen error"<<endl;
                return false;
            }
            return true;
        }

        bool Connect(const string &srv_ip,const string &srv_port)
        {
            //int connect(int sockfd, sockaddr *addr,socklen_t addrlen)
            struct sockaddr_in addr;
            addr.sin_family=AF_INET;
            addr.sin_port=htons(strtoint(srv_port));
            addr.sin_addr.s_addr=inet_addr(srv_ip.c_str());

            socklen_t len=sizeof(struct sockaddr_in);

            int ret=connect(_sockfd,(struct sockaddr*)&addr,len);

            if(ret<0)
            {
                cout<<"connect error"<<endl;
                return false;
            }
            return true;
        }

        bool Accept(TcpSocket& clientSock,string *ip=NULL,uint16_t *port=NULL)
        {
            struct sockaddr_in clientaddr;
            socklen_t len=sizeof(struct sockaddr_in);

            int newfd=accept(_sockfd,(struct sockaddr*)&clientaddr,&len);

            if(newfd<0)
            {
                cout<<"accept error"<<endl;
                return false;
            }

            clientSock.SetFd(newfd);
            if(ip!=NULL)
            {
                *ip=inet_ntoa(clientaddr.sin_addr);
            }
            if(port!=NULL)
            {
                *port=ntohs(clientaddr.sin_port);
            }
            return true;
        }

        bool Send(string &data)
        {
            int ret=send(_sockfd,&data[0],data.size(),0);

            if(ret<0)
            {
                cout<<"send error"<<endl;
                return false;
            }
            return true;
        }

        bool Recv(string &buf)
        {
            char tmp[4096]={0};
            int ret=recv(_sockfd,tmp,4096,0);

            if(ret<0)
            {
                cout<<"recv error"<<endl;
                return false;
            }
            else if(ret==0)
            {
                cout<<"connect shundown"<<endl;
                return false;
            }

            buf.assign(tmp,ret);
            return true;
        }

        void Close()
        {
            close(_sockfd);
        }
    private:
        int _sockfd;
};
