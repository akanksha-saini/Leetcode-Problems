/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
*/
//2 pointer approach is used

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


//2 pointer approach is used

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
       //empty list
        if(head==NULL)
            return NULL;
        
        ListNode* before = new ListNode();
        ListNode* after = new ListNode() ;
        ListNode* b = before;
        ListNode* a = after;
        
        while(head!=NULL)
        {
            if(head->val < x)
            {
                
                b->next = head; b = b->next;
                
            }
            else
            {
                a->next = head; a = a->next; 
            }
            head = head->next;
        }
        a->next = NULL;
        b->next = after->next;
        
        return before->next;
        
    } 
    
};
