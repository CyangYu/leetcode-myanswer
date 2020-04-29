#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode *prev = head;
        ListNode *node = head;

        while (node != nullptr) {
            int last = node->val;

            ListNode *prev0 = node;
            ListNode *node0 = node->next;

            while (node0 != nullptr) {
                if (node0->val == last) {
                    prev0->next = node0->next;
                } else {
                    prev0 = node0;
                }

                node0 = node0->next;
            }

            prev = node;
            node = node->next;
        }

        return head;
    }
};

                                                                                          
