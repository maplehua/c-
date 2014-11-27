#include<iostream>
#include "client.h"

using namespace std;

int main()
{
    Client client;
    client.client_connect("202.112.114.252", 3333);
    client.manage();
    return 0;
}
