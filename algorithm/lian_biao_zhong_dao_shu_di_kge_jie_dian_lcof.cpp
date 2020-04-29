#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    ListNode *kth;

    ListNode* getKthFromEnd(ListNode* head, int k) {
        int count = 1;

        getK(head, &count, k);
        return kth;
    }

    void getK(ListNode *node, int *count, int k) {
        if (node == nullptr) {
            return;
        }

        getK(node->next, count, k);
        if ((*count)++ == k) {
            kth = node;
            return;
        }
    }
};