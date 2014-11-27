#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<string>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/wait.h>
#include "serversocket.h"
#include "../library/log/log.h"
#include "../library/db/dbMysql.h"
#define SERVPORT 3333
#define BACKLOG 10 //MAX NUM OF CONNECT AT THE SAME TIME

using namespace std;

ServerSocket::ServerSocket(int serverPort = SERVPORT) {
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        Log::log(__FILE__,__LINE__,__FUNCTION__,"create socket error", 0);
        return;
    }
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(serverPort);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(my_addr.sin_zero), 8);
    if (bind(sock_fd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1) {
        Log::log(__FILE__,__LINE__,__FUNCTION__,"bind socket error", 0);
        return;
    }
    if (listen(sock_fd, BACKLOG) == -1) {
        Log::log(__FILE__,__LINE__,__FUNCTION__,"listen error", 0);
        return;
    }
}

int ServerSocket::ser_accept() {//error return -1
        sin_size = sizeof(struct sockaddr_in);
        if ((client_fd = accept(sock_fd, (struct sockaddr *)&remote_addr, (socklen_t *)&sin_size)) == -1) {
            Log::log(__FILE__,__LINE__,__FUNCTION__,"accept error", 0);
            return -1;
        }
        string str="received a connection from ";
        str+=inet_ntoa(remote_addr.sin_addr);
        cout<<str<<endl;
        Log::log(str, 0);
        if (!fork()) {
            DBMysql db;
            db.initDB("localhost", "root", "20062017", "xiaohua");
            string sendcontent;
            sendcontent = db.executeSQL("select content from civil_exam limit 1;");
            cout<<sendcontent<<endl;
            if (send(client_fd, sendcontent.c_str(), sendcontent.size(), 0) == -1) {
            cout<<"send error"<<endl;
            }
            string sendanswer;
            sendanswer = db.executeSQL("select answer from civil_exam limit 1;");
            cout<<sendanswer<<endl;
            if (send(client_fd, sendanswer.c_str(), sendanswer.size(), 0) == -1) {
            cout<<"send error"<<endl;
            }
            close(client_fd);
            return -1;
        }
            close(client_fd);
}
