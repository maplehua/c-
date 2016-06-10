#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if (head == NULL || head->next == NULL)
                return false;
            ListNode* step_1 = head->next;
            ListNode* step_2 = head->next->next;
            if (step_2 == NULL)
                return false;
            while (step_1 != step_2) {
                if (step_2->next == NULL || step_2->next->next == NULL)
                    return false;
                step_1 = step_1->next;
                step_2 = step_2->next->next;
            }
            return true;
        }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    head->next = node1;
    node1->next = node2;
    node2->next = head;
    cout<<solution.hasCycle(head)<<endl;

    return 0;
}
