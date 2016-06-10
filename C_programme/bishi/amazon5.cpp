#include<iostream>
#include<stdio.h>
#include<string.h>
#include<sstream>
#include<vector>

using namespace std;

void  split(vector<string> &vect, string str) {
    stringstream ss;
    ss<<str;
    string tmp;
    while (ss >> tmp) {
        vect.push_back(tmp);
    }

}

int compute(vector<string> &vect1, vector<string> &vect2) {
    int len1 = vect1.size();
    int len2 = vect2.size();
    if (len1 == 0) {
        return len2;
    }
    if (len2 == 0) {
        return len1;
    }
    int count = 0;
    vector<string>::iterator i= vect1.begin();
    //vector<string>::iterator iter = find(vect2.begin(), vect2.end(), *i);
    vector<string>::iterator j = vect2.begin();
    while (i != vect1.end() && j != vect2.end()) {
        if (*i == *j) {
           i++;
           j++;
        } else {
            i++;
            j++;
            count++;
        }
    }
    while (i != vect1.end())
    {
        i++;
        count++;
    }

    while (j != vect2.end()) {
        j++;
        count++;
    }
    return count;

}
int main()
{

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    vector<string> vect1, vect2;
    while (s1 != "" && s2 != "") {
        split(vect1, s1);
        split(vect2, s2);
        cout<<compute(vect1, vect2)<<endl;
        getline(cin, s1);
        getline(cin, s2);
        vect1.clear();
        vect2.clear();
    }

    return 0;
}
