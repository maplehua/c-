#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            vector<int>::iterator iter = nums.begin();
            int sum = 0;
            while (iter != nums.end()) {
                sum += *iter;
                iter++;
            }
            int res  = sum - (nums.size() - 1) * nums.size() / 2;
            return res;
        }
};

int main() {
    
    int arr[6] = {1,3,2,4,5,1};
    vector<int> vect(arr, arr + 6);
    Solution solution;
    cout<<solution.findDuplicate(vect)<<endl;

    return 0;
}
