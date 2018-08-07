#include "node.h"
#include <stdio.h>

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;
        
        ListNode *node = head, *prev = head;
        ListNode *curr = head;
        
        for (int i = 0; i < n - 1; i++) {
            if (node == nullptr)
                break;
            node = node->next;
        }

       if (node->next) {
            while (node->next) {
                prev = curr;
                curr = curr->next;
                node = node->next;
            }
       } else {
           curr = head->next;
           delete head;
           return curr;
       }
        
        prev->next = curr->next;
        delete curr;
        curr = nullptr;
        return head;
    }
};

int main(int argc, char *argv[]) 
{
    ListNode *head = new ListNode(1, nullptr);
    Solution solution;
    head = solution.removeNthFromEnd(head, 1);
    
    ListNode *node = head, *temp = head;

    while (node) {
        temp = node;
        printf("%d\n", node->val);
        delete node;
        node = temp->next;
    }

    return 0;
}