#include<unistd.h>
#include<iostream>
#include<fcntl.h>
#include<sys/stat.h>

#define FILENAME "data.txt"

using namespace std;

int main()
{
    int fd = open(FILENAME, O_RDWR);
    if (fd < 0) {
        cout<<"open file error--"<<endl;
        return -1;
    }

    struct stat buf;
    if (fstat(fd, &buf) < 0) {
        cout<<"fstat error"<<endl;
        return -1;
    }
    cout<<"uid = "<<buf.st_uid<<"\tgid = "<<buf.st_gid<<endl;
    //only test 2 types
    if (S_ISREG((buf.st_mode))) {
        cout<<"this is regular file"<<endl;
    } else if (S_ISDIR(buf.st_mode)) {
        cout<<"this is a directory"<<endl;
    } else {
        cout<<"this is another type file"<<endl;
    }

    if (access(FILENAME, W_OK) < 0) {
        cout<<"access error"<<endl;
    } else {
        cout<<FILENAME<<" can be written"<<endl;
    }
    
    if (fchmod(fd, S_IRUSR) < 0) {
        cout<<"chmod error"<<endl;
        return -1;
    }
    cout<<"after chmod ----read only------"<<endl;
    if (access(FILENAME, W_OK) < 0) {
        cout<<"access error"<<endl;  
    } else {
        cout<<FILENAME<<" can be written"<<endl;                
    }
    close(fd);

    return 0;
}
