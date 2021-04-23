/*
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> v;
        
        if(root==NULL)
            return v;
        
        //apply bfs
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v1;
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i=0; i<size; i++)
            {
               TreeNode* n =  q.front();
               q.pop();
               
                
                v1.push_back(n->val);
                
                if(n->left)
                    q.push(n->left);
                if(n->right)
                    q.push(n->right);
                
            } 
            v.push_back(v1);
            v1.clear();
        }
        return v;
    }
};
