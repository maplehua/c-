#include<iostream>
#include<stdio.h>
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>

#define SERVPORT 3333
#define MAXDATASIZE 100

using namespace std;

int main(int argc, char* argv[])
{
    int sock_fd,recvbytes;
    char buf[MAXDATASIZE];
    struct hostent *host;
    struct sockaddr_in serv_addr;
    if (argc < 2) {
        cout<<"error num parameter"<<endl;
        return -1;
    }
    if ((host = gethostbyname(argv[1])) == NULL) {
        cout<<"gethostname send an error"<<endl;
        return -1;
    }
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        cout<<"an error occurs when create socket"<<endl;
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVPORT);
    serv_addr.sin_addr = *((struct in_addr *)(host->h_addr));
    cout<<"host add is "<<host->h_addr<<endl;
    bzero(&(serv_addr.sin_zero), 8);
    if (connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr)) == -1) {
        cout<<"error occurs when connect"<<endl;
        return -1;
    }
    if ((recvbytes = recv(sock_fd, buf, MAXDATASIZE, 0)) == -1) {
        cout<<"error occurs when recv"<<endl;
        return -1;
    }
    buf[recvbytes] = '\0';
    cout<<*buf<<endl;
    close(sock_fd);

    return 0;
}
