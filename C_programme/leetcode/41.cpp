#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            vector<int>::iterator iter = nums.begin();
            int min = 25536, max = 0, sum = 0;
            while (iter != nums.end()) {
                if (*iter > max) {
                    max = *iter;
                }
                if (*iter < min && *iter > 0) {
                    min = *iter;
                }
                if (*iter > 0) 
                    sum += *iter;
                iter++;
            }
            if (sum == 0)
                return 1;
            if (max != 0 && sum == max && max >1)
                return max - 1;
            else if (max != 0 && sum == max && max ==1)
                return max + 1;
                
            if (sum == (max * (max + 1) / 2 - (min - 1) * min / 2))
                return max + 1;
            else 
                return max * (max + 1) / 2 - sum - (min - 1) * min / 2;
            
        }
};

int main() {
    int arr[4] = {3,4,-1,2};
    vector<int> nums;
    Solution s;
    cout<<s.firstMissingPositive(nums)<<endl;
    return 0;
}
