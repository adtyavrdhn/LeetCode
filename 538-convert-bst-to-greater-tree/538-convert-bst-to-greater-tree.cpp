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
    TreeNode* convertBST(TreeNode* root) 
    {
        f(root, 0);
        return root;
    }
    
    int f(TreeNode*root, int aboveSum)
    {
         if(!root) return 0;
        
        int right = f(root->right, aboveSum);
        int left = f(root->left, right + root->val + aboveSum);
        
        int sumBelow = root->val + left + right; 
        
        root->val += aboveSum + right;
        
        return sumBelow;
        
    }
};