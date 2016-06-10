#include<iostream>

using namespace std;

/**
 *  * Definition for singly-linked list.
 *  */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
    public:
        ListNode* removeElements(ListNode* head, int val) {
            if (head == NULL)
                return head;
            while (head != NULL && head->val == val) {
                ListNode *tmp = head;
                head = head->next;
                delete tmp;
            }
            if (head == NULL)
                return head;
            ListNode* cur = head->next;
            ListNode* pre = head;
            while (cur != NULL) {
                if (cur->val == val) {
                    ListNode* tmp = cur;
                    cur = cur->next;
                    pre->next = cur;
                    delete tmp;
                } else {
                    cur = cur->next;
                    pre = pre->next;
                }
            }
            return head;
        }
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    /*
    int arr[10] = {1,2,3,6,2,3,4,6,6,1};
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        ListNode* t = new ListNode(arr[i]);
        cur->next = t;
        cur = t;
    }
    */
    ListNode* h = head;
    while (h != NULL) {
        cout<<h->val<<"  ";
        h = h->next;
    }
    cout<<endl;
    Solution solution;
    ListNode* res = solution.removeElements(head, 1);
    while (res != NULL) {
        cout<<res->val<<"  ";
        res = res->next;
    }
    cout<<endl;
    return 0;
}
