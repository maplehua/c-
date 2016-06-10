#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        void swap(ListNode* first, ListNode* second) {
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
        ListNode* sortList(ListNode* head) {
            if (head == NULL || head->next == NULL)
                return head;
            if (head->next->next == NULL)
                if (head->next->val < head->val)
                    swap(head, head->next);
            int tmp = head->val;
            ListNode* p = head;
            ListNode* q = head->next;
            while (q != NULL) {
                if (q->val < tmp) {
                    swap(p, q);
                    p = p->next;
                }
                q = q->next;
            }
            sortList(head, p);
            if (p == head) p = p->next;
            sortList(p, NULL);
            return head;

        }
        void sortList(ListNode* begin, ListNode* end) {
            if (begin == NULL || begin->next == end || begin == end)
                return;
            int tmp = begin->val;
            ListNode* p = begin;
            ListNode* q = begin->next;
            while (q != end) {
                if (q->val < tmp) {
                    swap(p, q);
                    p = p->next;
                }
                q = q->next;
            }
            sortList(begin, p);
            if (begin == p) p = p->next;
            sortList(p, end);

        }
};

int main() {
    int arr[5] = {1,1,3,1,1};
    ListNode* head = new ListNode(2);
    ListNode* cur = head;
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        ListNode * tmp = new ListNode(arr[i]);
        cur->next = tmp;
        cur = tmp;
    }
    Solution solution;
    ListNode* res = solution.sortList(head);
    while (res != NULL) {
        cout<<res->val<< "  ";
        res = res->next;
    }
    cout<<endl;

    return 0;
}
