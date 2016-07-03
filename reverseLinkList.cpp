// Reverse a singly linked list.
// 
// click to show more hints.
// 
// Hint:
// A linked list can be reversed either iteratively or recursively. Could you implement both
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *reversedHead = head;
        if (head) {
            head = head->next;
            reversedHead->next = nullptr;
        }
        while (head) {
            ListNode *p = head;
            head = head->next;
            p->next = reversedHead;
            reversedHead = p;
        }
        return reversedHead;
    }
};
