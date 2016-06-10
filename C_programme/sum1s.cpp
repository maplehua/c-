#include<iostream>
using namespace std;

int count1(long n) {
    int tmp = 0;
    while (n != 0) {
        if (n%10 == 1) 
            tmp++;
        n/=10;
    }
    return tmp;
}

void sum1_1(long n) {
    int sum = 0;
    while (n > 0) {
        sum+=count1(n);
        n--;
    }
    cout<<"sum1_s = "<<sum<<endl;
}

void sum1_2(long n) {
    int sum = 0;
    long iFactor = 1;
    long iLowerNum = 0;
    long iCurNum = 0;
    long iHigherNum = 0;
    while (n / iFactor > 0) {
        iLowerNum = n - n/iFactor*iFactor;
        iCurNum = (n / iFactor) % 10;
        iHigherNum = n / (iFactor*10);
        switch (iCurNum) {
            case 0:
                sum+=iHigherNum*iFactor;
                break;
            case 1:
                sum = sum + iLowerNum+1 + iHigherNum*iFactor;
                break;
            default:
                sum+=(iHigherNum+1)*iFactor;

        }
        iFactor*=10;
    }
    cout<<"sum1_2 = "<<sum<<endl;
}

int main() {

    sum1_1(100000000);
    sum1_2(100000000);
    return 0;
}
