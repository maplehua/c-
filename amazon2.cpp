#include<iostream>
#include<string>
#include<math.h>
using namespace std;

bool isSymmerticNumber(int n) {
   int tmp = n, m = 0;
   while (tmp > 0) {
       m = m*10+tmp%10;
       tmp/=10;
   }
   return (m == n);
}

int getNextSymmetricNumber(int a) {
    if (a < 9)
       return a+1;
    while (true) {
        a++;
        if (isSymmerticNumber(a)) {
            break;
        }
    }
    return a;
}

//another way to find the next symmetric number
int getNextSymmetricNumber(string s) {
   int size = s.length();
   int n = 0;
   int *num = new int[size];
   int mid = size/2 + size%2;

   //turn the string into digit
   for (int i =0; i<size; i++) {
       num[i] = s[i] - '0';
       n = n*10 + num[i];
   }

   if (n < 9)
       return n+1;

   bool flag = false;
   int extra = -1;
   if (size%2 == 1) {
       for (int i = mid-2; i>=0; i--) {
           if (num[i] > num[(mid-1)*2 - i]) {
               flag = true;
               break;
           }
           if (num[i] < num[(mid-1)*2 - i]) {
               num[mid-1]++;
               flag = true;
               break;
           }
       }
       if (!flag)
           num[mid-1]++;
       for (int i = mid-1; i>0; i--)
           if (num[i] >= 10 ) {
               num[i-1] = num[i-1]+num[i]/10;
               num[i]%=10;
           }
       if (num[0] >= 10) {
        
           return pow(10, size)+1;
       }

       for (int i=0; i<mid-1; i++)
           num[size-i-1] = num[i];

   }
   if (size%2 == 0) {
       bool flag = false;
       for (int i =mid-1; i>=0; i--) {
           if (num[i] > num[size-i-1]) {
               flag = true;
               break;
           }
           if (num[i] < num[size-i-1]) {
               flag = true;
               num[i]++;
               break;
           }
       } 
       if (!flag)
           num[mid-1]++;
       for (int i= mid -1; i>0; i--) {
           if (num[i] >= 10) {
               num[i-1] = num[i]/10;
               num[i]%=10;
           }
       }
       if (num[0] >= 10)
           return pow(10, size)+1;
       for (int i=0; i<=mid-1; i++)
           num[size-i-1] = num[i];
   }

   int tmp = 0;
   for (int i=0; i<size; i++)
       tmp = tmp*10 + num[i];
   cout<<getNextSymmetricNumber(n)<<endl; 
   return tmp;
}

int main()
{
    //int a;
    string a;
    while(cin >> a) {
      cout<< getNextSymmetricNumber(a)<<endl;
      cout<<"-----------------------"<<endl;
    }
    return 0;
}

