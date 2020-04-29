#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    int kVal = 0;

    int kthToLast(ListNode* head, int k) {
        int count = 0;
        getKNode(head, &count, k);
        return kVal;
    }

    void getKNode(ListNode *node, int *count, int k) {
        if (node == nullptr) {
            return;
        }
        getKNode(node->next, count, k);
        if (++(*count) == k) {
            kVal = node->val;
            return;
        }
    }
};