#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

#define BUFFSIZE 30

using namespace std;

int main()
{
    int fd;
    if ((fd = open("data.txt", O_RDWR)) < 0) {
        cout<<"file create error!"<<endl;
        return -1;
    }

    char buf1[] = "#";
    char buf2[] = "################";

    if (write(fd, buf2, strlen(buf2)) != strlen(buf2)) {
        cout<<"write error"<<endl;
        return -1;
    }
    for (int i = 0; i<5; i++) {
        lseek(fd, 8, SEEK_CUR);
        if (write(fd, buf1, strlen(buf1)) != strlen(buf1)) {
            cout<<"write error"<<endl;
            return -1;
        }
        lseek(fd, 7, SEEK_CUR);
    }

    system("od -c data.txt");
    cout<<"==============================="<<endl;

    lseek(fd , 0, SEEK_SET);//be careful
    char buf[BUFFSIZE];
    while (read(fd, buf, BUFFSIZE) > 0) {
        string str(buf);
        cout<<str<<endl;
    }

    close(fd);
    return 0;
}

