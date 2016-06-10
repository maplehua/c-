#include<iostream>
#include<stdlib.h>
using namespace std;

int getLevelNum(int level) {
    if (level == 1)
        return 1;
    return 3*getLevelNum(level-1);
}

int getLevelCount_real(int level) {
   if (level == 1)
       return 1;
   return  getLevelNum(level)+getLevelCount_real(level-1);
}

int getLevelCount(int level) {
   return getLevelCount_real(level) -1;//begin with 0
}

int judgeLevel(int n) {
    int level = 1;
    while(getLevelCount(level) < n)
        level++;
    return level;
}

bool isSameLevel(int n, int m) {
    return judgeLevel(n) == judgeLevel(m);
}

//get the Data at the position m in the given level
//assume the m according the direction of the tree
int get(int level, int m) {
    if (level == 1)
        return 0;
    int count = getLevelCount(level - 1);
    return count+m;
}

//level % 2  increase (0:from left to right  1:from right to left )
int getParent(int n) {
    int level = judgeLevel(n);
    int deta = (n - getLevelCount(level-1));
    if (deta %3 != 0)
        deta+=3;
    int pos = deta/3;
    return get(level-1, getLevelNum(level-1)-pos+1);//for reverse order
}

int findCommonParent(int n, int m) {
    if (isSameLevel(n, m)) {
        if (abs(n-m)<3)
            return getParent(n);
    }
    if (n < m) {
        int t = n;
        n = m;
        m = t;
    }
    while (!isSameLevel(n, m)) {
       n = getParent(n);
       if (n == m)
           return n;
    }
    while (n!=m) {
       n = getParent(n);
       m = getParent(m);
    }
    return n;
}

int main()
{
    int n = -1, m = -1;
    while (cin>>n>>m) {
       cout<<findCommonParent(n, m)<<endl;
    }
    //cout<<getParent(2)<<endl;
    //cout<<getParent(2)<<endl;
    return 0;
}
