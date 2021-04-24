/*You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

 

Example 1:


Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       
        if(root==NULL)
        {
            root = new TreeNode(val);
            return root;
        }
        
        TreeNode* curr = root;
        while(1)
        {
            if(val < curr->val)
            {
                if(curr->left != NULL)
                    curr = curr->left;
                
                else
                {
                   curr->left = new TreeNode(val);
                    break;
                }
                    
                    
            }
            else
            {
                if(curr->right != NULL)
                    curr = curr->right;
                
                else
                {
                    curr->right = new TreeNode(val);
                    break;
                }
                    
            }
            
        }
        
        return root;
        
        /* recursive solution - space complexity is O(n) so use iterative only it's space complexity is O(1)
        if(root==NULL)
        {
            root = new TreeNode(val);
            return root;
        }
        else
        {
            if(val < root->val)
            {
              root->left =  insertIntoBST(root->left,val);
            }
            else
                root->right = insertIntoBST(root->right, val);
        }
        return root;
      */
       
        
    }
};
