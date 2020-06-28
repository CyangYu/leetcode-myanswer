#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode newNode(1, head);
        ListNode *prev = nullptr, *curr = nullptr;

        newNode.next = head;
        prev = &newNode;
        curr = head;

        while (curr != nullptr) {
            if (curr->val == val) {
                ListNode *next = curr->next;
                prev->next = next;
                curr = next;
            } else {
                if (curr != nullptr) {
                    prev = curr;
                    curr = curr->next;
                }
            }
        } 

        return newNode.next;  
    }
};
