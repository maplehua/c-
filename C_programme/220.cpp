#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Solution {
    public:
            bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
                if (nums.size() == 0) return false;
                for (int i = 0; i < nums.size(); i++) {
                    for (int j = i + 1; j < nums.size() && j <= i + k; j++) {
                        int a = nums[i];
                        int b = nums[j];
                        if (a < b) { a = nums[j]; b = nums[i];}
                        if (a - b <= t)
                            return true;
                    }
                    
                }
                return false;
            }
};
