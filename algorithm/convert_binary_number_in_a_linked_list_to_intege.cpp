#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num = 0;
        ListNode *node = head;

        while (node != nullptr) {
            num = (num << 1) | node->val;
            node = node->next;
        }

        return num;
    }
};

