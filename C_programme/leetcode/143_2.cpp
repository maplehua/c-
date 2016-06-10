#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
    public:
        void reorderList(ListNode* head) {
            if (head == NULL || head->next == NULL)
                return ;
            int size = 0;
            ListNode* cur = head;
            while (cur != NULL) {
                size++;
                cur = cur->next;
            }
            int sep = size / 2;
            ListNode* head2 = head;
            while (sep > 1) {
                head2 = head2->next;
                sep--;
            }
            ListNode* tmp = head2->next;
            head2->next = NULL;
            head2 = tmp;
            head2 = reverseList(head2);
            ListNode* p1 = head;
            ListNode* p2 = head2;
            while (p1 != NULL && p2 != NULL) {
                ListNode* t = p2->next;
                p2->next = p1->next;
                p1->next = p2;
                p1 = p2->next;
                p2 = t;
                
            }
            if (p2 != NULL) {
                p1 = head;
                while (p1->next != NULL) p1 = p1->next;
                p1->next = p2;
            }

        }

        ListNode* reverseList(ListNode* head) {
            if (head == NULL || head->next == NULL)
                return head;
            ListNode* pre = head;
            ListNode* cur = head->next;
            ListNode* next = head->next->next;
            while (next != NULL) {
                cur->next = pre;
                pre = cur;
                cur = next;
                next = next->next;
            }
            cur->next = pre;
            head->next = NULL;
            head = cur;
            return head;

        }
};

int main() {

    Solution solution;
    ListNode* head = new ListNode(1);
    /*
    int arr[4] = {2,3,4,5};
    ListNode* cur = head;
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        ListNode* t = new ListNode(arr[i]);
        cur->next = t;
        cur = t;
    }
    */
    solution.reorderList(head);
    ListNode* cur = head;
    while (cur != NULL) {
        cout<<cur->val<<"  ";
        cur = cur->next;
    }
    cout<<endl;
    return 0;
}
