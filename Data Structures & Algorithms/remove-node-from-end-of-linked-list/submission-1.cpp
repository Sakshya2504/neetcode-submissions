/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* tail = head;
        while(tail != nullptr){
            size++;
            tail = tail->next;
        }
        tail = head;
        int required = size-n-1;
        if(required < 0 && size == 1) return nullptr;
        if(required < 0 && n == size){
            return head->next;
        }
        while(required > 0){
            tail = tail->next;
            required--;
        }
        ListNode* temp = tail->next->next;
        tail->next = temp;
        return head;
    }
};
