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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL)
            return NULL;
        
        if(key < root->val)
        {
            root->left = deleteNode(root->left,key);
            return root;
        }
        if(key > root->val )
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        else
        {
            if(root->left == NULL && root->right == NULL) //root has no child
            {
                delete root;
                root = NULL;
                return root;
            }
            
            else if(root->left!=NULL && root->right == NULL) //root has one left child
            {
                TreeNode* temp;
                temp = root->left;
                delete root;
                root = NULL;
                return temp;
            }
            else if(root->left == NULL && root->right != NULL) //root has one right child
            {
                TreeNode* temp;
                temp = root->right;
                delete root;
                root = NULL;
                return temp;
            }
            
            else //root has both child
            {
                TreeNode* replaceNode = root->right;
                
                while(replaceNode->left != NULL)
                {
                    replaceNode = replaceNode->left;
                }
                int temp = root->val;
                root->val = replaceNode->val;
                replaceNode->val  = temp;
                
                root->right = deleteNode(root->right, key);
                return root;
            }
        }
    }
};
