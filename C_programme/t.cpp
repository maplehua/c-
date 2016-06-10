#include<iostream>
#include<vector>
#include<iterator>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    
    int myints[] = {10,20,30,30,30,30,40,50};
    std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20
    vector<int>::iterator last = unique(v.begin(), v.end()); 
    
   unordered_multimap<string, string> smap = {
   {"a", "cai"}, {"a", "xiaohua"}, {"c", "d"}
    };
    pair<iterator, iterator> res = smap.equal_range("a");
    cout<<res.first<<endl;
    
    return 0;
}
