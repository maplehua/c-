#ifndef SERVER_H
#define SERVER_H
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>
class ServerSocket {
    public:
        ServerSocket(int port);
        int ser_accept();//error when return -1
    private:
        int sock_fd;
        int client_fd;
        int sin_size;
        struct sockaddr_in my_addr;
        struct sockaddr_in remote_addr;
    
};


#endif
