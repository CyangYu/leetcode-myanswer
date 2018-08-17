#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    inline size_t linked_list_size(ListNode *head) {
        ListNode *node = head;
        size_t size = 0;
        
        while (node != nullptr) {
            node = node->next;
            size++;
        }

        return size;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *nodeA = headA, *nodeB = headB;

        size_t sizeA = linked_list_size(headA);
        size_t sizeB = linked_list_size(headB);

        ListNode *maxSizeList = nullptr;
        ListNode *minSizeList = nullptr;
        size_t diff = 0;

        if (sizeA > sizeB) {
            maxSizeList = headA;
            minSizeList = headB;
            diff = sizeA - sizeB;
        } else {
            maxSizeList = headB;
            minSizeList = headA;
            diff = sizeB - sizeA;
        }

        ListNode *nodeA = maxSizeList;
        ListNode *nodeB = minSizeList;

        for (int i = 0; i < diff; i++)
            nodeA = nodeA->next;
        
        while (nodeA != nullptr && nodeB != nullptr) {
            if (nodeA == nodeB)
                return nodeA;
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }

        return nullptr;
    }
};