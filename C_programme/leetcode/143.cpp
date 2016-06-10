#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
    public:
        ListNode* getIndexNode(ListNode* begin, int dis) {
            if (begin == NULL)
                return begin;
            ListNode* cur = begin;
            while (cur != NULL && dis > 0) {
                cur = cur->next;
                dis--;
            }
            return cur;
        }
        void reorderList(ListNode* head) {
            if (head == NULL || head->next == NULL)
                return ;
            int size = 0;
            ListNode* cur = head;
            while (cur != NULL) {
                size++;
                cur = cur->next;
            }
            cur = head;
            if (size >= 3) {
                ListNode* tmp = getIndexNode(head, size - 1);
                getIndexNode(head, size - 2)->next = NULL;
                ListNode* next = cur->next;
                cur->next = tmp;
                tmp->next = next;
                cur = next;
                reorderList(cur);
            } else {
                return;
            }

        }
};

int main() {

    Solution solution;
    ListNode* head = new ListNode(1);
    //int arr[2] = {2,3};
    ListNode* cur = head;
    //for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
      //  ListNode* t = new ListNode(arr[i]);
      //  cur->next = t;
      //  cur = t;
   // }
    solution.reorderList(head);
    cur = head;
    while (cur != NULL) {
        cout<<cur->val<<"  ";
        cur = cur->next;
    }
    cout<<endl;
    return 0;
}
