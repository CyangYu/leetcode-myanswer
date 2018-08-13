#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode *node = head;

        while (node != nullptr) {
            node = node->next;
            size++;
        }

        node = head;
        for (int i = 0; i < size / 2; i++) {
            node = node->next;
        }

        return node;
    }
};

