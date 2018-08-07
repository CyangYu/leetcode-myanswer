#include <stdio.h>

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *node) : val(x), next(node) {}
} ListNode;


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         if (!l1 && !l2)
            return NULL;
        
        if (l1 && !l2)
            return l1;

        if (!l1 && l2)
            return l2;
        
        ListNode *min = (l1->val <= l2->val) ? l1 : l2;
        ListNode *max = (l1->val >  l2->val) ? l1 : l2;
        
        ListNode *node1 = min, *node2 = max;
        ListNode *prev = min, *next = max;
        
        while (1) {
            while (node1 && node2) {
                if (node2->val < node1->val) {
                    next = node2->next;
                    prev->next = node2;
                    node2->next = node1;
                    prev = node2;
                    node2 = next;
                    break;
                } else {
                    prev = node1;
                    node1 = node1->next;
                }
            }

            if (!prev->next|| !node2)
                break;
        }
        
        if (node2)
            prev->next = node2;
        return min;
    }
};

int main(int argc, char *argv[])
{
    ListNode *l1 = new ListNode(-10,
                   new ListNode(-9,
                   new ListNode(-6,
                   new ListNode(-4,
                   new ListNode(1,
                   new ListNode(9,
                   new ListNode(9, NULL)))))));

    ListNode *l2 = new ListNode(-5,
                   new ListNode(-3,
                   new ListNode(0,
                   new ListNode(7,
                   new ListNode(8,
                   new ListNode(8, NULL))))));

    Solution solution;
    ListNode *list = solution.mergeTwoLists(l1, l2);

    ListNode *temp1 = list, *temp2 = list;

    while (temp1 != NULL) {
        temp2 = temp1;
        printf("%d\n", temp1->val);
        delete temp1;
        temp1 = temp2->next;
    } 

    return 0;
}