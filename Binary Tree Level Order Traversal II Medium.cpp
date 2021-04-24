/*Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> v;
        
        
        if(root==NULL)
            return v;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> v1;
            for(int i=0; i<size; i++)
            {
                TreeNode* n = q.front();
                q.pop();
                v1.push_back(n->val);
                
                if(n->left)
                    q.push(n->left);
                if(n->right)
                    q.push(n->right);
            }
            v.push_back(v1);
            
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
