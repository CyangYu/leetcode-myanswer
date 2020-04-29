#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;
        ListNode *node = headA;

        while (node != nullptr) {
            s.insert(node);
            node = node->next;
        }

        node = headB;
        while (node != nullptr) {
            if (s.find(node) != s.end()) {
                return node;
            }

            node = node->next;
        }

        return nullptr;
    }
};