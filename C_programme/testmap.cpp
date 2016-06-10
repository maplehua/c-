#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main()
{
    map<int, vector<int> > m;
    vector<int> vect;
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    m[0] = vect;

    for(vector<int>::iterator iter = m[0].begin(); iter != m[0].end(); iter++) {
        cout<<*iter<<"\t";
    }
    cout<<endl;

    vector<int> tmp = m[0];
    tmp.push_back(4);
    m[0] = tmp;
    
    for(vector<int>::iterator iter = m[0].begin(); iter != m[0].end(); iter++) {
        cout<<*iter<<"\t";
    }
    cout<<endl;


    vector<int> tmp2 = m[0];
    tmp2.push_back(5);
    m.insert(pair<int, vector<int> >(0, tmp2));
    
    for(vector<int>::iterator iter = m[0].begin(); iter != m[0].end(); iter++) {
        cout<<*iter<<"\t";
    }
    cout<<endl;

    return 0;
}
