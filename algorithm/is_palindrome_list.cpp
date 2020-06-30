#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
      /**
     * @param head a ListNode
     * @return a boolean
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        if(head == nullptr) return nullptr;

        ListNode *next = head->next;
        head->next = nullptr;
        while(next != nullptr)
        {
            ListNode *tmp = next->next;
            next->next = head;
            head = next;
            next = tmp;
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
