// Remove all elements from a linked list of integers that have value val.
// 
// Example
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
// Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        // Delete head until its value differs from val. 
        while (head) {
            if (head->val != val)
                break;
            ListNode *t = head;
            head = head->next;
            delete t;
        }

        // delete internal nodes.
        if (head) {
            // previous node
            ListNode *p = head;

            // the node being examined.
            ListNode *q = head->next;

            while (q) {
                if (q->val != val) {
                    p = q;
                    q = q->next;
                } else {
                    ListNode *t = q;
                    q = q->next;
                    p->next = q;
                    delete t;
                }
            }
        }

        return head;
    }
}
