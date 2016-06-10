#include "unistd.h"
#include <iostream>
using namespace std;

#define BUFFSIZE 4096
int main()
{
    int n =0;
    char buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        if ((n = write(STDOUT_FILENO, buf, n)) != n) {
            cout<<"write error"<<endl;
        }
    }

    if (n < 0) {
        cout<<"read error"<<endl;
    }


    return 0;
}
