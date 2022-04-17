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
    TreeNode* increasingBST(TreeNode* root) 
    {
     TreeNode* sentinel = new TreeNode(0);
        TreeNode* ans = sentinel;
        dfs(root, sentinel);
        return ans->right;
        
    }
    
     void dfs(TreeNode* root, TreeNode*& sentinel) 
     {
        if(!root) return;
         
        dfs(root->left, sentinel);
         
        TreeNode* newNode = new TreeNode(root->val);
        sentinel->right = newNode;
        sentinel = sentinel->right;
        dfs(root->right, sentinel);
        return;
    }
};