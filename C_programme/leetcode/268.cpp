#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            vector<int>::iterator iter = nums.begin();
            int sum = 0;
            int max = 0;
            while (iter != nums.end()) {
                sum += *iter;
                if (*iter > max) max = *iter;
                iter++;
            }
            if (max != nums.size())
                return nums.size();
            int res = nums.size() * (nums.size() + 1) / 2 - sum;
            return res;
        }
};


int main() {

    int arr[3] = {0,1,2};
    vector<int> vect(arr, arr + 3);
    Solution solution;
    cout<<solution.missingNumber(vect)<<endl;
    return 0;
}
