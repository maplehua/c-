#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<netdb.h>

#define SERVPORT 3333
#define MAXDATASIZE 100

using namespace std;

int main(int argc, char* argv[])
{
    int sock_fd, recvbytes;
    char buf[MAXDATASIZE];
    struct hostent *host;
    struct sockaddr_in serv_addr;
    if (argc < 2) {
        cout<<"wrong parameter numbers"<<endl;
        return -1;
    }
    if ((host = gethostbyname(argv[1])) == NULL) {
        cout<<"get hostname error"<<endl;
        return -1;
    }
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        cout<<"create socket error"<<endl;
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVPORT);
    serv_addr.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr.sin_zero), 8);
    if (connect(sock_fd, (struct sockaddr *)&serv_addr, (socklen_t)sizeof(struct sockaddr)) == -1) {
        cout<<"connect error"<<endl;
        return -1;
    }
    if ((recvbytes = recv(sock_fd, buf, MAXDATASIZE, 0)) == -1) {
        cout<<"recv error"<<endl;
        return -1;
    }
    buf[recvbytes] = '\0';
    cout<<buf<<endl;
    close(sock_fd);

    return 0;
}
