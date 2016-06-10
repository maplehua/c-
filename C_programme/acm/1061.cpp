#include<iostream>
using namespace std;

int main()
{
    int x,y,m,n,l;
    while (cin>>x>>y>>m>>n>>l) {
        long long int count = 0;
        int tmp1 = 0, tmp2 = 0;
        while (true) {
            tmp1 = (l*1.0/2+x+m*count)-l*(int)((l*1.0/2+x+m*count)/l);
            tmp2 = (l*1.0/2+y+n*count)-l*(int)((l*1.0/2+y+n*count)/l);
            if (tmp1 == tmp2) {
                cout<<count<<endl;
                break;
            }

            if (tmp1 ==x && tmp2 == y) {
                cout<<"Impossible"<<endl;
                break;
            }
            count++;
            if (tmp1 < tmp2 && m<=n) {
                count+=(l/2-y)/n;
            }
            if (tmp1>tmp2 && m>=n) {
                count+=(l/2-x)/m;
            }
        
        }
    }

    return 0;
}
