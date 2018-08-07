#include "node.h"
#include <iostream>

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

int main()
{
    Solution s1;
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(4);
    ListNode *n3 = new ListNode(3);
    ListNode *n7 = new ListNode(7);
    n1->next = n2;
    n2->next = n3;
    n3->next = n7;
    
    ListNode *n4 = new ListNode(5);
    ListNode *n5 = new ListNode(6);
    ListNode *n6 = new ListNode(4);
    ListNode *n8 = new ListNode(8);
    n4->next = n5;
    n5->next = n6;
    n6->next = n8;

    ListNode *n = s1.addTwoNumbers(n1, n4);
    ListNode *temp = n;
    for (int i = 0; i < 5; i++) {
        std::cout << temp->val << '\n';
        temp = temp->next;
    }
    
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    return 0;
}


