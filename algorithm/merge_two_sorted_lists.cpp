#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         if (!l1 && !l2)
            return NULL;
        
        if (l1 && !l2)
            return l1;

        if (!l1 && l2)
            return l2;
        
        ListNode *min = (l1->val <= l2->val) ? l1 : l2;
        ListNode *max = (l1->val >  l2->val) ? l1 : l2;
        
        ListNode *node1 = min, *node2 = max;
        ListNode *prev = min, *next = max;
        
        while (1) {
            while (node1 && node2) {
                if (node2->val < node1->val) {
                    next = node2->next;
                    prev->next = node2;
                    node2->next = node1;
                    prev = node2;
                    node2 = next;
                    break;
                } else {
                    prev = node1;
                    node1 = node1->next;
                }
            }

            if (!prev->next|| !node2)
                break;
        }
        
        if (node2)
            prev->next = node2;
        return min;
    }
};