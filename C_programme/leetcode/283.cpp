#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            vector<int>::iterator iter_1 = nums.begin();            
            vector<int>::iterator iter_2 = nums.begin();
            while (iter_2 < nums.end()) {
                while (iter_2 < nums.end() && *iter_2 == 0) iter_2++;
                if (iter_2 < nums.end()) {
                    *iter_1 = *iter_2;
                    iter_1++;
                    iter_2++;
                }
            }
            while (iter_1 != nums.end()) {
                *iter_1 = 0;
                iter_1++;
            }
        }
};

int main() {
    int arr[5] = {1,1,0,3,12};
    vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
    Solution solution;
    solution.moveZeroes(nums);
    vector<int>::iterator iter = nums.begin();
    while (iter != nums.end()) {
        cout<<*iter<<"  ";
        iter++;
    }
    cout<<endl;

    return 0;
}
