#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{

    int fd[2];
    if (pipe(fd) == -1) {
        cout<<"create pipe error"<<endl;
        return -1;
    }

    if (fork() == 0) {
        close(fd[1]);
        char buf[100];
        if (!read(fd[0], buf, 100)) {
            cout<<"read error"<<endl;
            exit(-1);
        }

        cout<<"the child process get the content is : =="<<string(buf)<<endl;
        cout<<"the child process is end"<<endl;
    } else {
    
        close(fd[0]);
        char buf[] = "Hello World!";
        if (write(fd[1], buf, strlen(buf)) != strlen(buf)) {
            cout<<"write error"<<endl;
            exit(-1);
        }
        cout<<"the parent is end"<<endl;
    }

    return 0;
}

