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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
         return lca(root,p,q);
    }
    
   TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(p==root || q==root || !root)
        {
            return root;
        }
       
        TreeNode* left = lca(root->left,p,q);
        TreeNode* right = lca(root->right,p,q);
       
        if(left&&right)
        {
           return root;
        }
       
       return left ? left : right;
    }
};