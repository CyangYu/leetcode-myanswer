#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head = ListNode(0);
        ListNode *next = &head;
        ListNode *n1 = l1, *n2 = l2;
        
        while (n1 != nullptr && n2 != nullptr) {
            if (n1->val < n2->val) {
                next->next = n1;
                n1 = n1->next;
            } else {
                head.next = n2;
                n2 = n2->next;
            }

            next = next->next; 
        }

        while (n1 != nullptr) {
            next->next = n1;
            next = next->next;
            n1 = n1->next;
        }

        while (n2 != nullptr) {
            next->next = n2;
            next = next->next;
            n2 = n2->next;
        }

        return head.next;
    }
};