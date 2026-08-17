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
    ListNode* reverseList(ListNode* head) {
        ListNode* tail = head;
        ListNode* prev = NULL;

        while(head != nullptr){
            tail = head->next;
            head->next = prev;
            prev = head;
            head = tail;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* temp2 = head;
        while(temp2 != nullptr){
            ListNode* temp1 = head->next;
            ListNode* temp3 = reverseList(temp1);
            head->next = temp3;
            head = head->next;
            temp2 = temp2->next;
        }
    }
};
