#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
using namespace std;

class Solution {
    public:
       bool containsNearbyDuplicate(vector<int>& nums, int k) {
          if (nums.size() == 0) {return false;} 
          if (nums.size() <= k) {
            map<int, int> maps;
            for (int i = 0; i < nums.size(); i++) {
                maps[nums[i]] = i;
            }
            if (maps.size() != nums.size())
                return true;
            return false;
          }
          map<int, int> maps;
          for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            for (int j = i; j <= i + k && j < nums.size(); j++) {
                maps[nums[j]] = j;
                count++;
            }
            if (maps.size() < count)
                return true;
            maps.clear();
            if (nums.size() - i < k)
                return false;
            
          }
          return false;
    }
};

int main() {
    Solution s;
    int a[] = {1, 2, 1};
    vector<int> nums(a, a + sizeof(a)/sizeof(int));
    cout<<s.containsNearbyDuplicate(nums, 1)<<endl;;

}
