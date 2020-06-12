#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr)
            return nullptr;

        set<ListNode *> listset;
        ListNode *node = head;

        while (true) {
            if (listset.find(node) == listset.end()) {
                listset.insert(node);
            } else 
                break;

            node = node->next;
            if (node == nullptr)
                return nullptr;
        }
        
        return node;
    }
};
