#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
              std::vector<int> v;
        int carry = 0, n = 0;

        ListNode *node1 = l1, *node2 = l2;
        ListNode *prev = l1;

        while (node1 && node2) {
            n = node1->val + node2->val + carry;
            if (n >= 10) {
                n -= 10;
                carry = 1;
            } else {
                carry = 0;
            }

            v.push_back(n);
            prev = node1;
            node1 = node1->next;
            node2 = node2->next;
        }

        while (node1) {
            n = node1->val + carry;
            if (n >= 10) {
                n -= 10;
                carry = 1;
            } else {
                carry = 0;
            }

            v.push_back(n);
            prev = node1;
            node1 = node1->next;
        }

        while (node2) {
            n = node2->val + carry;
            if (n >= 10) {
                n -= 10;
                carry = 1;
            } else {
                carry = 0;
            }

            v.push_back(n);
            node2 = node2->next;
        }
        
        if (carry == 1) 
            v.push_back(1);
        
        node1 = l1;
        prev->next = l2;

        for (int i = 0; i < v.size(); i++) {
            node1->val = v[i];
            prev = node1;
            node1 = node1->next;
        }

        l2 = node1;
        prev->next = nullptr;
        return l1;
    }
};