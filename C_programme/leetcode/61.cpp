#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
           if (head == NULL || head->next == NULL || k <= 0)
               return head;
           ListNode* cur = head;
           int size = 0;
           ListNode* end = NULL;
           ListNode* start = NULL;
           while (cur != NULL) {
               size++;
               end = cur;
               cur = cur->next;
           }
           k = k % size;
           //cout<<k<<" "<<size<<endl;
           cur = head;
           int i = size - k;
           if (i == size) {
               return head;
           }
            while (i-- > 1) 
                cur = cur->next;
            ListNode* tmp = cur->next;
            cur->next = NULL;
            end->next = head;
            head = tmp;
           return head;

        }
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    for (int i = 2; i < 3; i++) {
        ListNode* tmp = new ListNode(i);
        cur->next = tmp;
        cur = tmp;
    }
    Solution solution;
    ListNode* res  = solution.rotateRight(head, 2);
    while (res != NULL) {
        cout<<res->val<<"  ";
        res = res->next;
    }
    cout<<endl;
    return 0;
}
