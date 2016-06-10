#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
using namespace std;

int main()
{
    pid_t pid;
    if ((pid = fork()) < 0) {
        cout<<"create process error"<<endl;
        return -1;
    } else if (pid == 0) {
        if ((pid = fork()) < 0) {
            cout<<"create process error in inter fork"<<endl;
            return -1;
        } else if (pid > 0) {
            cout<<"[Child--1] I'm the first child. [Child] pid ="<<pid<<endl;
            exit(0);//the parent exit to avoid zombie
        }
        sleep(2);
        cout<<endl;
        cout<<"[Child--2] I'm the second child. my pid = "<<getpid()<<" and my parent pid = "<<getppid()<<endl;
        exit(0);
    } else {
        cout<<"[Parent] I'm the first parent. I'm waitting for [Child] pid = "<<pid<<endl;
        if (waitpid(pid, NULL, 0) != pid) { 
            cout<<"waiting error"<<endl;
            exit(-1);
        } else {
            cout<<"[Parent] I've receive from my child."<<endl;
        }
    }


    return 0;
}
