#include <iostream>
#include <cstring>
#include <stdlib.h>
//#include <sys/socket.h>
#include <winsock.h>
#include <winsock2.h>
#pragma comment(lib,“ws2_32.lib”)
#include <sys/types.h>
//#include <netinet/in.h>
//#include <netinet/ip.h>
//#include <arap/inet.h>
#include <unistd.h>

using namespace std;

class TcpSocket
{
private:
    char *ip;
    int port;
    int sockfd;
    int listen_n;
    sockaddr_in saddr;
    int acceptfd;
    sockaddr_in caddr;
    socklen_t caddr_len;

public:
    TcpSocket(string _ip, int _port)
    {
        ip = (char *)_ip.data();
        port = _port;
        listen_n = 10;
        memset(&saddr, 0, sizeof(saddr));
        //bzero(&caddr, sizeof(struct sockaddr_in));
        caddr_len = sizeof(caddr);
    }

    ~TcpSocket()
    {
        close(sockfd);
        if(acceptfd > 0)
            close(acceptfd);
    }

    int tcp_server_init()
    {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(-1 == sockfd)
        {
            perror("socket");
            return -1;
        }

        int b_ruse = 1;
        if(-1 == setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &b_ruse, sizeof(int)))
        {
            perror("setsockopt");
            return -1;
        }

        saddr.sin_family = AF_INET;
        saddr.sin_port = htons(port);
        saddr.sin_addr.s_addr = inet_addr(ip);
        if(-1 == bind(sockfd, (sockaddr *)&saddr, sizeof(saddr)))
        {
            perror("bind");
            return -1;
        }
        if(-1 == listen(sockfd, listen_n))
        {
            perror("listen");
            return -1;
        }
        puts("listen-------");
        return sockfd;
    }

    int tcp_wait_connect()
    {
        acceptfd = accept(sockfd, (sockaddr *)&caddr, &caddr_len);
        if(-1 == acceptfd)
        {
            perror("accept");
            return -1;
        }
        printf("IP:%s PORT:%d connected.\n", inet_ntoa(caddr.sin_addr), ntohs(caddr,sin_port));
        return acceptfd;
    }

    int tcp_client()
    {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(-1 == sockfd)
        {
            perror("socket");
            return -1;
        }
        saddr.sin_family = AF_INET;
        saddr.sin_port = htons(port);
        saddr.sin_addr.s_addr = inet_addr(ip);
        int confd = connect(sockfd, (sockaddr *)&saddr, sizeof(saddr));
        if(confd < 0)
        {
            perror("connect");
            return -1;
        }
        printf("connect success.\n");
        return sockfd;
    }
    void set_listen_n(int n)
    {
        listen_n = n;
    }
};