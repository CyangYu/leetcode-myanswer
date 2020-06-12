#include <stdio.h>

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *node) : val(x), next(node) {}
} ListNode;

class Solution {
public:
      /**
     * @param head a ListNode
     * @return a boolean
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        if(head == NULL)
            return NULL;
        ListNode *Next = head->next;
        head->next = NULL;
        while(Next != NULL)
        {
            ListNode *tmp = Next->next;
            Next->next = head;
            head = Next;
            Next = tmp;
        }
        return head;
    }
    
    bool isPalindrome(ListNode* head) {
        // Write your code here
        if(head == NULL)
           return true;

        //快慢指针寻找链表的中点

        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //翻转后半部分

        slow->next = reverse(slow->next);
        ListNode *pre = head;

        //比较前半部分和后半部分

        while(slow->next)
        {
            slow = slow->next;
            if(pre->val != slow->val)
              return false;
            
            pre = pre->next;
        }
        return true;
    }
};
