#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode newNode(1, head);
        ListNode *prev = nullptr, *curr = nullptr;

        newNode.next = head;
        prev = &newNode;
        curr = head;

        while (curr != nullptr) {
            if (curr->val == val) {
                ListNode *next = curr->next;
                prev->next = next;
                delete curr;
                curr = next;
            } else {
                if (curr != nullptr) {
                    prev = curr;
                    curr = curr->next;
                }
            }
        } 

        return newNode.next;  
    }
};

int main(int argc, char *argv[])
{
    ListNode *list = new ListNode(1, new ListNode(1, nullptr));
    Solution solution;
    list = solution.removeElements(list, 1);

    ListNode *node1 = list, *node2 = list;
    while (node1 != nullptr) {
        node2 = node1->next;
        cout << node1->val << ' ';
        delete node1;
        node1 = node2;
    }

    cout << endl;

    return 0;
}