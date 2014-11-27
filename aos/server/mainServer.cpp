#include<iostream>
#include "serversocket.h"

using namespace std;

int main()
{
    ServerSocket ss(3333);
    while(true) {
        if (ss.ser_accept() != -1) {
            cout<<"ok"<<endl;
        }
    }
    return 0;
}
