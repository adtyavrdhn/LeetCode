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
    map<pair<TreeNode*,bool>,int> mpp;
    int rob(TreeNode* root) 
    {
        return f(root,true);
    }
    int f(TreeNode* root, bool canrob)
    {
        if(!root)
        {
            return 0;
        }
        
        if(mpp.find({root,canrob})!=mpp.end())
        {
            return mpp[{root,canrob}];
        }
        
        int rob = -1e9, nrob = -1e9;
        
        if(canrob)
        {
            rob = root->val + f(root->left,false) + f(root->right,false);
        }
        nrob = f(root->left,true) + f(root->right,true);
        
        return mpp[{root,canrob}] = max(rob,nrob);
    }
};