#include<iostream>
#include<string.h>
#include<map>
#include<string>
using namespace std;

void compute(char c[], int &count) {
    int size = strlen(c);
    for (int i =0; i<size-1; i++) {
        for (int j=i+1; j<size; j++) {
            if (c[i] > c[j])
                count++;
        }
    }        
}

int main()
{
    int m , n;
    map<int ,string> mp;
    int count = 0;
    string str;
    while (cin>>n>>m) 
    {
        for(int i=0; i<m; i++){
            cin>>str;
            char *c = new char[str.length()+1];
            strcpy(c, str.c_str());
            compute(c, count);
            if (mp.find(count) != mp.end()) {
                string s = mp[count];
                s.append("\n"+str);
                mp[count] = s;
            } else {
                mp[count] = str;
            }
            count = 0;
        }
        map<int , string>::iterator iter = mp.begin();
        while (iter != mp.end()) {
            cout<<iter->second<<endl;
            iter++;
        }
        mp.clear();
    }
    return 0;
}
