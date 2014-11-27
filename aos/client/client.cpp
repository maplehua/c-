#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<netdb.h>
#include "client.h"
#include "../library/log/log.h"
#define SERVPORT 3333

using namespace std;

void Client::client_connect(string hostname="202.112.114.252", int port = SERVPORT) {
    if ((host = gethostbyname(hostname.c_str())) == NULL) {
            Log::log(__FILE__,__LINE__,__FUNCTION__,"get hostname error", 1);
        return;
    }
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            Log::log(__FILE__,__LINE__,__FUNCTION__,"create socket error", 1);
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVPORT);
    serv_addr.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr.sin_zero), 8);
    if (connect(sock_fd, (struct sockaddr *)&serv_addr, (socklen_t)sizeof(struct sockaddr)) == -1) {
        Log::log(__FILE__,__LINE__,__FUNCTION__,"connect error", 1);
        return;
    }
    /*
    if ((recvbytes = recv(sock_fd, buf, MAXDATASIZE, 0)) == -1) {
        Log::log(__FILE__,__LINE__,__FUNCTION__,"recv error", 1);
        return;
    }
    buf[recvbytes] = '\0';
    cout<<buf<<endl;
    close(sock_fd);
    */
}

void Client::manage() {
    cout<<"Welcome to Civil Servants Exam. Please enjoy it."<<endl;
    int quesNum = 1;
    string choice = "Y";
    while (choice.compare("N") != 0) {
    send(sock_fd, "Yes", 3, 0);
    if ((recvbytes = recv(sock_fd, buf, MAXDATASIZE, 0)) == -1) {
        Log::log(__FILE__,__LINE__,__FUNCTION__,"recv error", 1); 
        return;
    }
    buf[recvbytes] = '\0';
    char bufTmp[10];
    if ((recvbytes = recv(sock_fd, bufTmp, 10, 0)) == -1) {      
        Log::log(__FILE__,__LINE__,__FUNCTION__,"recv error", 1);      
        return;
    }  
    bufTmp[recvbytes] = '\0';
    cout<<quesNum++<<"."<<buf<<endl;
    string answer(bufTmp);
    cout<<"Please enter your answer here : "<<endl;
    string input;
    cin>>input;
    if (answer.compare(input) != 0) {
        cout<<"Sorry. Wrong Answer."<<endl;
        cout<<"The answer is "<<bufTmp<<endl;
    } else {
        cout<<"Well Done."<<endl;
    }
    cout<<"The next question ? Y or N :";
    cin>>choice;
    }//end while
    cout<<"Thanks. Have a nice time."<<endl;
}
