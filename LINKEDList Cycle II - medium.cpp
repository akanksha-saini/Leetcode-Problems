/*
https://leetcode.com/problems/linked-list-cycle-ii/
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Notice that you should not modify the linked list.

sol : Using Floyd Cycle Detection Algo
*/

class Solution {
public:
    ListNode* checkCycle(ListNode* &head)
    {
       if(head==NULL )
            return NULL;
    
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!= NULL && fast->next != NULL )
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow)
                return slow;
        }
        return NULL;
 
    }
    ListNode *detectCycle(ListNode *head) {
       
        if(head==NULL || head->next==NULL )
            return NULL;
        ListNode *intersect = checkCycle(head);
        
        ListNode* start = head;
        
        if(intersect == NULL)
            return NULL;
        while(start != intersect )
        {
            intersect = intersect->next;
            start = start->next;
        }
        return start;
        
    }
};
