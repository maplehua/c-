#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        void addRes(vector<vector<int> >& res, stack<TreeNode*> s) {
            if (s.size() == 0) return;
            vector<int> vect;
            stack<int> reverse;
            while (!s.empty()) { reverse.push(s.top()->val); s.pop();}
            while (!reverse.empty()) { vect.push_back(reverse.top()); reverse.pop();}
            res.push_back(vect);
        }

        vector<vector<int> > pathSum(TreeNode* root, int sum) {
            vector<vector<int> > resList;
            if (root == NULL) return resList;
            stack<TreeNode*> s;
            s.push(root);
            int tmp_sum = 0;
            tmp_sum += root->val;
            while (s.size() != 0) {
                TreeNode* node = s.top();
                if (node->left != NULL) {
                    s.push(node->left);
                    tmp_sum += node->left->val;
                    node->left = NULL;
                    continue;
                }
                if (node->right != NULL) {
                    s.push(node->right);
                    tmp_sum += node->left->val;
                    node->right = NULL;
                    continue;
                }
                if (tmp_sum == sum) {
                    addRes(resList, s);
                }
                tmp_sum -= node->val;
                s.pop();
            
            }
            return resList;
        }
};

int main() {
    

    return 0;
}

