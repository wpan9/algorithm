// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
      if (!l1) return l2;
      if (!l2) return l1;

      ListNode *root = 0;
      ListNode *current = 0;

      // l1 != 0 && l2 != 0;
      while (true) {
        if (l1->val <= l2->val) {
          if (current == 0) {
            root = current = l1;
            l1 = l1->next;
          } else {
            current->next = l1;
            current = l1;
            l1 = l1->next;
          }
        } else {
          if (current == 0) {
            root = current = l2;
            l2 = l2->next;
          } else {
            current->next = l2;
            current = l2;
            l2 = l2->next;
          }
        }

        if (l1 == 0) {
          current->next = l2;
          return root;
        }

        if (l2 == 0) {
          current->next = l1;
          return root;
        }
      }

      return root;
    }
};
