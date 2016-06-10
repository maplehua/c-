#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

using namespace std;

void sig_user(int signo) {
    if (signo == SIGCHLD) {
        cout<<"[Parent] receive signal from child."<<endl;
    } else {
        cout<<"receive signal that I can't control. singno = "<<signo<<endl;
    }
}

int main()
{
    pid_t pid;
    if ((pid = fork()) < 0) {
        cout<<"create process error"<<endl;
        return -1;
    } else if (pid == 0) {
        cout<<"[Child] I'm going to exit and return my info."<<endl;
        return 0;
    } else {
        if (signal(SIGCHLD, sig_user) == SIG_ERR) {
            cout<<"can't catch SIGCHLD."<<endl;
            exit(0);
        }
        sleep(3);
    }

    return 0;
}
