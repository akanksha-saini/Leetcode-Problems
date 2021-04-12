/* Problem 234
Given the head of a singly linked list, return true if it is a palindrome.


Example 1:
Input: head = [1,2,2,1]
Output: true

*/
class Solution {
    
    ListNode* midLL(ListNode* head)
    {
        if(head== NULL)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast!= NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
public:
    bool isPalindrome(ListNode* head) {
        
        //find middle of LL
        ListNode* ptr  = midLL(head);
        
        ptr  = ptr->next;
        
        //reverse the right half
        
        ListNode* curr = ptr;
        ListNode* prev = NULL;
        while(curr!=NULL)
        {
            ListNode* n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        //reversed right half will be retrieved from prev
        
        ListNode* dummy = head;
        while(1)
        {
            if(prev == NULL)
                return true;
            if(dummy->val == prev->val)
            {
                dummy = dummy->next;
                prev = prev->next;
            }
            else
                return false;
            
        }
        return false;
    }
};
