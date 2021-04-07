//Given the head of a singly linked list, reverse the list, and return the reversed list.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp;
        
        if(curr == NULL)
            return prev;
        
        reverseList(head)
        while(curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
      return prev;  
    }
};
