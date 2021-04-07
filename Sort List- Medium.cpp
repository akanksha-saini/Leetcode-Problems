/*
Sort a LL in O(logn) TC and O(1) SC

*/
class Solution {
    
    ListNode* midLL(ListNode* &head)
    {
        if(head == NULL || head->next == NULL)
            return head;

         ListNode* slow = head;
         ListNode* fast = head->next;
        
        while(fast!= NULL && fast->next!= NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
     ListNode* merge( ListNode* &l1,  ListNode* &l2)
     {
         if(l1 == NULL)
            return l2;
         if(l2 == NULL)
             return l1;
         
         ListNode* temp; 
         if(l1->val <= l2->val)
         {
             temp = l1;
             ListNode* restNode =  merge(l1->next, l2);
             temp->next = restNode;
         }
         else
         {
             temp = l2;
             ListNode* restNode =  merge(l1, l2->next);
             temp->next = restNode;
         }
         return temp;
     }
public:
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return head;
         ListNode* mid = midLL(head);
         ListNode* secondHalf = mid->next;
         mid->next = NULL;
        
        head = sortList(head);
        secondHalf = sortList(secondHalf);
        ListNode* finalList = merge(head, secondHalf);
        
        return finalList;
        
    }
};
