#include<iostream>
using namespace std;

int main() {
    int a[] = {1,2,3,4,1,2,3};
    for (int i = 1; i< sizeof(a)/sizeof(int); i++)
        a[0] = a[0]^a[i];
    cout<<a[0]<<endl;

    return 0;
}
