#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

#define BUFFSIZE 4096
int main()
{
    int file = open("data.txt", O_RDWR);
    int n;
    char buf[BUFFSIZE];
    lseek(file, 5, SEEK_SET);
    while ((n = read(file, buf, BUFFSIZE)) > 0 ) {
        printf("%s\n", buf);
    }
    char content[]="hello world!";
    lseek(file, 200, SEEK_SET);
    if (write(file, content, 12) != 12) {
        printf("write error");
    }
    close(file);

exit(0);
}
