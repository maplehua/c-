#include<iostream>
#include<unistd.h>

using namespace std;

int main()
{

    int count = 0;
    int fd;
    if ((fd = fork()) == 0) {
        cout<<"this is the child process"<<endl;
        count++;
        cout<<"child process : count = "<<count<<endl;
    } else {
        cout<<"this is the parent process"<<endl;
        count++;
        cout<<"parent process count = "<<count<<endl;
    }

    cout<<"count = "<<count<<endl;
    cout<<"this is the end"<<endl;

    return 0;
}
