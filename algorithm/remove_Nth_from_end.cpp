#include "node.h"
#include "common.h"

USESTD 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;
        
        ListNode *node = head, *prev = head;
        ListNode *curr = head;
        
        for (int i = 0; i < n - 1; i++) {
            if (node == nullptr) break;
            node = node->next;
        }

       if (node->next) {
            while (node->next) {
                prev = curr;
                curr = curr->next;
                node = node->next;
            }
       } else {
           curr = head->next;
           return curr;
       }
        
        prev->next = curr->next;
        return head;
    }
};