#pragma once

#include<iostream>
#include<string>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

using namespace std;

#define CHECK_RET(q) if((q)==false){return -1;}

class Socket
{
    public:

        bool Sock()
        {
            //int socket(int domain, int type, int protocol);
            _sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);

            if(_sockfd<0)
            {
                cout<<"socket error"<<endl;
                return false;
            }
            return true;
        }

        bool Bind(const string &ip,const uint16_t port)
        {
            //int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
            struct sockaddr_in addr;
            addr.sin_family=AF_INET;

            //uint16_t htons(uint16_t hostshort);
            addr.sin_port=htons(9000);

            //将点分十进制字符串IP地址转换为网络字节序格式的ip地址
            addr.sin_addr.s_addr=inet_addr(ip.c_str());

            int ret;
            socklen_t len=sizeof(struct sockaddr_in);

            ret=bind(_sockfd,(struct sockaddr*)&addr,len);

            if(ret<0)
            {
                cout<<"bind error"<<endl;
                return false;
            }
            return true;
        }

        bool Send(const string &data,const string &peer_ip,const uint16_t peer_port)
        {
            //ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
                //const struct sockaddr *dest_addr, socklen_t addrlen);
            struct sockaddr_in addr;
            addr.sin_family=AF_INET;
            addr.sin_port=htons(peer_port);

            addr.sin_addr.s_addr=inet_addr(peer_ip.c_str());

            socklen_t len=sizeof(struct sockaddr_in);

            int ret=sendto(_sockfd,&data[0],data.size(),0,(struct sockaddr*)&addr,len);

            if(ret<0)
            {
                cout<<"send error"<<endl;
                return false;
            }
            return true;
        }

        bool Recv(string &buf,string &peer_ip,uint16_t &peer_port)
        {
            //ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                        //struct sockaddr *src_addr, socklen_t *addrlen);
            struct sockaddr_in peer_addr;

            socklen_t len=sizeof(struct sockaddr_in);

            char tmp[4096]={0};

            int ret=recvfrom(_sockfd,tmp,4096,0,(struct sockaddr*)&peer_addr,&len);

            if(ret<0)
            {
                cout<<"recv error"<<endl;
                return false;
            }

            peer_ip=inet_ntoa(peer_addr.sin_addr);
            peer_port=ntohs(peer_addr.sin_port);

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