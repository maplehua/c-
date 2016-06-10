#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
 
class Solution {
    public:

        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* head = l1;
            ListNode* pre = NULL;
            while (l1 != NULL && l2 != NULL) {
                l1->val += l2->val;
                pre = l1;
                l1 = l1->next;
                l2 = l2->next;
            }
            if (l2 != NULL)
                if (l1 != NULL)
                    l1->next = l2;
                else
                    pre->next = l2;
            l1 = head;
            while (l1 != NULL) {
                if (l1->val >= 10) {
                    if (l1->next == NULL) {
                        ListNode* end = new ListNode(l1->val / 10);
                        l1->next = end;
                    } else {
                        l1->next->val += l1->val / 10;
                    }
                    l1->val %= 10;
                }
                l1 = l1->next;
            }
            return head;
        }
};

int main() {

    ListNode * head1 = new ListNode(2);
    head1->next = new ListNode(4);
    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(7);
    Solution solution;
    ListNode* res = solution.addTwoNumbers(head1, head2);
    while (res != NULL) {
        cout<<res->val<<" ";
        res = res->next;
    }
    cout<<endl;
    return 0;
}
