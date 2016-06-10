#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
 
class Solution {
    public:
        int parseList(ListNode* head) {
            ListNode* cur = head;
            int res = 0;
            while (cur != NULL) {
                res = res * 10 + cur->val;
                cur = cur->next;
            }
            return res;
        }

        ListNode* createList(int num) {
            int tmp = num % 10;
            num /= 10;
            ListNode* head = new ListNode(tmp);
            ListNode* cur = head;
            while (num > 0) {
                tmp = num % 10;
                num /= 10;
                ListNode* t = new ListNode(tmp);
                cur->next = t;
                cur = t;
            }
            return head;
        }
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int n1 = parseList(l1);
            int n2 = parseList(l2);
            int res = n1 + n2;
            return createList(res);
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
