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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) 
    {
        f(root); 
        
        return res;
    }
    int f(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        
        int left = max(0,f(root->left));
        int right = max(0,f(root->right));
        
        res = max(res, left+right+root->val);
        
        return max(left,right) + root->val;
    }
};