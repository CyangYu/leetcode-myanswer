#include <stdio.h>

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution {
public:
    bool hasCycle(ListNode *head) {
         if (!head || !head->next)
        return false;
    
    ListNode *node1, *node2;
    node1 = node2 = head;
    
    while (node1 && node2 && node2->next) {
        node2 = node2->next->next;
        node1 = node1->next;
        
        if (node1 == node2) {
            return true;
        }
    }
    
    return false;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}