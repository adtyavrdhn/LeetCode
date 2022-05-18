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
    int maxAncestorDiff(TreeNode* root) 
    {
        if(!root) return 0;
        
     int mx = INT_MIN, mn = INT_MAX;
            
        f(root,mx,mn);
        return res;
    }
    void f(TreeNode* root,int mx, int mn)
    {
        if(!root) return;
        
        
        mx=max(mx,root->val);
        mn=min(mn,root->val);
        
        res = max(res,mx-mn);
        
        
        f(root->left,mx,mn);
        f(root->right,mx,mn);
    }
};