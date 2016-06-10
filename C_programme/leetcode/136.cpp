#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
           vector<int>::iterator iter = nums.begin();
           int res = 0;
           while (iter != nums.end()) {
               res ^= *iter++;
           }
           return res;
        }
};


int main() {

    int arr[3] = {0,2,2};
    vector<int> vect(arr, arr + 3);
    Solution solution;
    cout<<solution.singleNumber(vect)<<endl;
    return 0;
}
