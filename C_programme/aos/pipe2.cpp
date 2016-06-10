#include<iostream>
#include<unistd.h>
#include<fcntl.h>
using namespace std;

int main()
{
    int fd = open("data.txt", O_RDWR|O_CREAT);
    if (fd < 0) {
        cout<<"open error"<<endl;
        return -1;
    }
    cout<<"please enter your password : ";
    close(1);
    dup(fd);
    close(fd);
    sleep(5);
    cout<<endl;
    cout<<"you have done here;"<<endl;
    return 0;
}
