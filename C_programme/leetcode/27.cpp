#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            if (nums.size() == 0)
                return 0;
            vector<int>::iterator iter_1 = nums.begin();
            vector<int>::iterator iter_2 = nums.begin();
            int i = 0;
            while (iter_2 < nums.end()) {
                while (iter_2 != nums.end() && *iter_2 == val) iter_2++;
                if (iter_2 < nums.end()) {
                    *iter_1 = *iter_2;
                    iter_1++;
                    iter_2++;
                    i++;
                }
            }
            vector<int> t(nums.begin(), nums.begin() + i);
            nums = t;
            return i;
        }
};

int main() {
    Solution solution;
    int arr[4] = {3,2,2,3};
    vector<int> vect(arr, arr + sizeof(arr)/sizeof(int));
    solution.removeElement(vect, 3);

    vector<int>::iterator iter = vect.begin();
    while (iter != vect.end()) {
        cout<<*iter<< " ";
        iter++;
    }
    cout<<endl;
    return 0;
}
