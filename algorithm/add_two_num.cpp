#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    void swap(ListNode **n1, ListNode **n2) {
        ListNode *temp;

        temp = *n1;
        *n1 = *n2;
        *n2 = temp;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *answer = new ListNode(0);
        ListNode *node1 = l1;
        ListNode *node2 = l2;
        ListNode *node3 = answer;
        static int count = 0;
        bool flag = false;

        while (node1 != nullptr || node2 != nullptr) {
            if (flag == true) {
                node3->val += 1;
                flag = false;
            }

            if ((node3->val += node1->val + node2->val) >= 10) {
                flag = true;
                node3->val -= 10;
            }
            
            ListNode *temp = new ListNode(0);
            swap(&node3, &temp);
            temp->next = node3;
            
            node1 = node1->next;
            node2 = node2->next;
            count += 1;
        }

        ListNode *temp = answer;
        for (int i = 0; i < count - 1; i++) 
            temp = temp->next;
        if (temp->next != nullptr && temp->next->val == 0) {
            delete temp->next;
            temp->next = nullptr;
        }
        
        return answer;
    }
};


