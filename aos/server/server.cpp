#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/wait.h>

#define SERVPORT 3333
#define BACKLOG 10 //MAX NUM OF CONNECT AT THE SAME TIME

using namespace std;

int main()
{
    int sock_fd, client_fd;
    int sin_size;
    struct sockaddr_in my_addr;
    struct sockaddr_in remote_addr;
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        cout<<"create socket error"<<endl;
        return -1;
    }
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(SERVPORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(my_addr.sin_zero), 8);
    if (bind(sock_fd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1) {
        cout<<"bind error"<<endl;
        return -1;
    }
    if (listen(sock_fd, BACKLOG) == -1) {
        cout<<"listen error"<<endl;
        return -1;
    }
    while (true) {
        sin_size = sizeof(struct sockaddr_in);
        if ((client_fd = accept(sock_fd, (struct sockaddr *)&remote_addr, (socklen_t *)&sin_size)) == -1) {
            cout<<"accept error"<<endl;
            return -1;
        }
        cout<<"received a connection from "<<inet_ntoa(remote_addr.sin_addr)<<endl;
        if (!fork()) {
            if (send(client_fd, "hello, you are connected~\n", 26, 0) == -1) {
            cout<<"send error"<<endl;
            }
            if (send(client_fd, "A\n", 2, 0) == -1) {
            cout<<"send error"<<endl;
            }
            close(client_fd);
            return -1;
        }
            close(client_fd);
    }

    return 0;
}
