#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            if (head == NULL || head->next == NULL)
                return NULL;
            ListNode* step_1 = head->next;
            ListNode* step_2 = head->next->next;
            if (step_2 == NULL)
                return NULL;
            while (step_1 != step_2) {
                if (step_2->next == NULL || step_2->next->next == NULL)
                    return NULL;
                step_1 = step_1->next;
                step_2 = step_2->next->next;
            }
            ListNode* t = head;
            while (t != step_1) {
                t = t->next;
                step_1 = step_1->next;
            }
            return step_1;
        }
};
int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    head->next = node1;
    node1->next = node2;
    node2->next = node1;
    cout<<solution.detectCycle(head)->val<<endl;

    return 0;
}
