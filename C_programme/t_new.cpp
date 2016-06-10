#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;


int main()
{
    int c[] = {3,2,1};
    do {
    cout<<c[0]<<c[1]<<c[2]<<endl;
    } while( std::next_permutation(c,c+3) );

return 0;
}
