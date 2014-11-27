#ifndef CLIENT_H
#define CLIENT_H
#include<string>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/types.h>
#define MAXDATASIZE 1024
using namespace std;
class Client{
    public:
        void client_connect(string hostname, int port);
        void manage();
    private:
        int sock_fd;
        int recvbytes;
        char buf[MAXDATASIZE];
        struct hostent *host;
        struct sockaddr_in serv_addr;
};

#endif
