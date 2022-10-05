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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(depth==1)
        {
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            
            return temp;
        }
        
        f(root,val,1,depth);
        
        return root;
    }
    void f(TreeNode* root, int val, int level, int depth)
    {
        if(!root || level>=depth)
        {
            return;
        }
        
        if(level == depth-1)
        {
            TreeNode* left = new TreeNode(val);
            left->left = root->left;
            root->left = left;
            
            TreeNode* right = new TreeNode(val);
            right->right = root->right;
            root->right = right;
        }
        
        f(root->left,val,level+1,depth);
        f(root->right,val,level+1,depth);
    }
};