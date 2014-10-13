#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
    string s;
    cout<<"input string"<<endl;
    cin>>s;
    do
    {
       cout<<s<<endl;
    } while (next_permutation(s.begin(), s.end()));

    char buf[50];
    cout<<"input char"<<endl;
    cin>>buf;
    do {
        cout<<buf<<endl;
    } while (next_permutation(buf, buf+strlen(buf)));

    return 0;
}
