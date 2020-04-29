#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }

        bool flag = true;
        int length = 0, current = 0;
        ListNode *out = head;
        
        isPalindromeList(head, &out, &length, &current, &flag);
        return flag;
    }

    void isPalindromeList(ListNode *node, ListNode **out, int *length, int *current, bool *flag) {
        if (node == nullptr) {
            return;
        }

        (*length)++;

        isPalindromeList(node->next, out, length, current, flag);
        
        if (*current == *length / 2) {
            return;
        }

        if (node->val != (*out)->val) {
            *flag = false;
            return;
        }

        (*current)++;
        *out = (*out)->next;
    }
};