/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        h(root,p,q);  
        return res;
    }
    void h(TreeNode* root,TreeNode* p, TreeNode* q)
    {
        if(!root)
            return;
        
        
        if(p->val > root->val && q->val>root->val)
        {
            h(root->right,p,q);
        }
        
        else if(p->val < root->val && q->val < root->val)
        {
            h(root->left,p,q);
        }
        
        else
        {
            res = root;
            return;
        }
    }
};