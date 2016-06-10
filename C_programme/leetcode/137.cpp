#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
           vector<int>::iterator iter = nums.begin();
           int max = 0;
           while (iter != nums.end()) {
               if (*iter > max)
                   max = *iter;
               iter++;
           }
           iter = nums.begin();
           int *arr = new int[max + 1];
           for (int i = 0; i < max + 1; i++) arr[i] = 0;
           while (iter != nums.end()) {
                arr[*iter]++;
                iter++;
           }
           for (int i = 0; i < max + 1; i++)
               if (arr[i] == 1)
                   return i;
        }
};


int main() {

    int arr[4] = {0,0,0,5};
    vector<int> vect(arr, arr + 4);
    Solution solution;
    cout<<solution.singleNumber(vect)<<endl;
    return 0;
}
