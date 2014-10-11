#include<iostream>
#include<strings.h>
//string.size()  string[i]
#include<algorithm>
//std::sort()
#include<string.h>
//memset()
using namespace std;

#define SAME_4 6
#define SHUN   5
#define SAME_3 4
#define SAME_2_2 3
#define SAME_2 2
#define SAME_1 1

//the way to get input deal with the ','
//the way to use the function like sort() memset()
//the way to debug the programme

void charToNum(string a, int arr[]) {
    int index = 0;
    for (int i = 0; i< a.size(); i++) {
        switch(a[i]) {
            case 'A':
                arr[index++] = 14;
                break;
            case 'J':
                arr[index++] = 11;
                break;
            case 'K':
                arr[index++] = 13;
                break;
            case 'Q':
                arr[index++] = 12;
                break;
            case '1':
                arr[index++] = 10;
                i++;
                break;
            case ',':
                break;
            default:
                arr[index++] = a[i] - '0';
                break;
        }
    
    }
    cout<<endl;
}

void displayArr(const int a[], int size){
   for (int i = 0; i<size; i++) {
       cout<<a[i]<<"\t";
   }
   cout<<endl;
}

bool isShun(int arr[], int size) {
    std::sort(arr,arr+size);
    if (arr[3] == 14 && arr[2] == 4 && arr[1] == 3 && arr[0] == 2) {
        arr[3] = 1;
        std::sort(arr, arr+size);
        return true;
    }
    for (int i=1; i<size; i++)
        if (arr[i]-arr[i-1] != 1)
            return false;
    return true;
}

int judgePattern(int arr[], int size) {
    int digit[15];
    memset(digit, 0, sizeof(digit)/sizeof(int));
    for (int i=0; i< size; i++) {
       digit[arr[i]]++;
    }
    int num_2 = 0;
    for (int i=1; i<15; i++) {
       if (digit[i] == 4)
           return SAME_4;
       if (digit[i] == 3)
           return SAME_3;
       if (digit[i] == 2)
           num_2++;
    }
    if (num_2 == 2)
        return SAME_2_2;
    if (num_2 == 1)
        return SAME_2;
    if (isShun(arr,size))
        return SHUN;
    return SAME_1;
}

void compare(int aa[], int pattern1, int bb[], int pattern2) {
    std::sort(aa, aa+4);
    std::sort(bb, bb+4);
    switch(pattern1) {
        case SAME_4:
            {
            if (aa[0] > bb[0])
                cout<<"1 win pattern = "<<pattern1<<endl;
            else if (aa[0] < bb[0])
                cout<<"2 win pattern = "<<pattern1<<endl;
            break;
            }
        case SHUN:
            {
            if (aa[3] > bb[3])
                cout<<"1 win pattern = "<<pattern1<<endl;
            else if (aa[3] < bb[3])
                cout<<"2 win pattern = "<<pattern1<<endl;
            else
                cout<<"1 == 2  pattern = "<<pattern1<<endl;
            break;
            }
        case SAME_3:
            {
            int xx = -1, yy = -1;
            if (aa[0] == aa[1])
                xx = aa[0];
            else
                xx = aa[3];
            if (bb[0] == bb[1])
                yy = bb[0];
            else
                yy = bb[3];
            if (xx > yy) {
                cout<<"1 win pattern = "<<pattern1<<endl;
            } else  {
                cout<<"2 win pattern = "<<pattern1<<endl;
            }
            break;
            }
        case SAME_2_2:
            {
            if (aa[3] > bb[3]) {
                cout<<"1 win pattern1="<<pattern1<<endl;
            } else if (aa[3] < bb[3]) {
                cout<<"2 win pattern1="<<pattern1<<endl;
            } else {
                if (aa[0] > bb[0])
                    cout<<"1 win pattern1="<<pattern1<<endl;
                else if (aa[0] < bb[0])
                    cout<<"2 win pattern1="<<pattern1<<endl;
                else
                    cout<<"1==2 pattern1="<<pattern1<<endl;
            }
            break;
            }
        case SAME_2:
            {
            int xx = -1, yy = -1;
            if (aa[0] == aa[1])
                xx = aa[0];
            else if (aa[1] == aa[2])
                xx = aa[1];
            else
                xx = aa[2];
            
            if (bb[0] == bb[1])
                yy = bb[0];
            else if (bb[1] == bb[2])
                yy = bb[1];
            else 
                yy = bb[2];

            if (xx > yy)
                cout<<"1 win"<<endl;
            else if (xx < yy)
                cout<<"2 win"<<endl;
            else {
                bool flag = false;
                for (int j = 3; j>=0; j--){
                   if (aa[j] != bb[j]) {
                       flag = true;
                       if (aa[j] > bb[j])
                           cout<<"1 win"<<endl;
                       else 
                           cout<<"2 win"<<endl;
                   }
                } 
                if (!flag)
                     cout<<"1==2"<<endl;
            }
            break;
           }
        case SAME_1:
            {
            bool flag = false;
            for (int j =3; j>=0; j--) {
                if (aa[j] != bb[j])
                    flag = true;
                if (aa[j] > bb[j])
                {
                    cout<<"1 win"<<endl;
                    break;
                }
                if (aa[j] < bb[j]) {
                    cout<<"2 win"<<endl;
                    break;
                }
            }
            if (!flag)
                cout<<"1==2"<<endl;
            break;
            }
        default:
            break;
            
    }
}

int main()
{

    string a,b;
    int aa[4], bb[4];
    while (cin>>a>>b) {
       cout<<"input : a = "<<a<<endl;
       cout<<"input : b = "<<b<<endl;
       charToNum(a, aa);
       charToNum(b, bb);
       
       int pattern1 = judgePattern(aa, sizeof(aa)/sizeof(int));
       int pattern2 = judgePattern(bb, sizeof(bb)/sizeof(int));

       if (pattern1 > pattern2) {
           cout<<"1 win pattern1 = "<<pattern1<<" pattern2 = "<<pattern2<<endl;
           continue;
       } else if (pattern1 < pattern2) {
           cout<<"2 win pattern1 = "<<pattern1<<" pattern2 = "<<pattern2<<endl;
           continue;
       } else {
           compare(aa, pattern1, bb, pattern2);
       }
           
    }

    return 0;
}
