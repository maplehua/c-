#include<iostream>
#include<unistd.h>
#include<string.h>
using namespace std;

int main()
{
    int pend1[2],pend2[2];
    char buf[1024];
    if (pipe(pend1) < 0 || pipe(pend2) < 0) {
        cout<<"create pipe error"<<endl;
        return -1;
    }
    pid_t pid;
    if ((pid = fork()) < 0) {
        cout<<"create process error"<<endl;
        return -1;
    } else if (pid == 0) {
        close(pend1[1]);
        close(pend2[0]);// read from pend1 and write to pend2
        if (read(pend1[0], buf, 1024) < 0) {
            cout<<"[Child] read error"<<endl;
            return -1;
        }
        cout<<"[Child] message from parent : "<<string(buf)<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"[Child] say something to parent : ";
        string tmp;
        getline(cin, tmp);
        if (write(pend2[1], tmp.c_str(), strlen(tmp.c_str())) != strlen(tmp.c_str())) {
            cout<<"[Child] write error"<<endl;
            return -1;
        }
        cout<<"-----------------------------------------"<<endl;
        
    } else {
        close(pend1[0]);
        close(pend2[1]);
        cout<<"[Parent] say something to the child : ";
        string tmp;
        getline(cin, tmp);
        if (write(pend1[1], tmp.c_str(), strlen(tmp.c_str())) != strlen(tmp.c_str())) {
            cout<<"[Parent] write error"<<endl;
            return -1;
        }
        cout<<"-----------------------------------------"<<endl;
        if (read(pend2[0], buf, 1024) < 0) {
            cout<<"[Parent] read error"<<endl;
            return -1;
        }
        cout<<"[Parent] message from child : "<<string(buf)<<endl;
    }

    return 0;
}
