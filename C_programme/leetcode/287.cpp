#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<int>::iterator iter = nums.begin();
            while (iter != nums.end()) {
                if (*iter == *(iter + 1))
                    return *iter;
                iter++;
            }
        }
};

int main() {
    
    int arr[6] = {1,3,2,4,5,1};
    vector<int> vect(arr, arr + 6);
    Solution solution;
    cout<<solution.findDuplicate(vect)<<endl;

    return 0;
}
