#include<iostream>
#include<vector>
using namespace std;
//1.24 29 34 0
//2. 1 57 67 1
//3. be careful about the time to output
int main()
{

    int index = 1;
    int a, b, c, d;
    int ans;
    while (cin>>a>>b>>c>>d) {
        if (a==b && a==c && a==d && a==-1) {
            return 0;
        }
        bool found = false;
        for (int i=0; !found; i++) {
           if ((a+23*i-b)%28 == 0)
               if ((a+23*i-c)%33 == 0)
                   if ((a+23*i) != d)
                   {
                       if (a+23*i > d) {
                           ans = a+23*i-d;
                           ans%=21252;
                           while (ans <=0) ans+=21252;
                           cout<<"Case "<<index++<<": the next triple peak occurs in "<<ans<<" days."<<endl;;
                           break;
                       }
                   } 
        }
        
    }

return 0;
}
