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
    string res="zzzzzzzzzzzzzzzzzzzzzzzzzz";
    string smallestFromLeaf(TreeNode* root) 
    {
        
        f(root,"");
        return res;
    }
    
    void f(TreeNode* root,string s)
    {
        s+= root->val+'a';
        
        if(!root->left && !root->right)
        {
            reverse(s.begin(),s.end());
            
            res = min(res,s);
            
            return;
        }
        
        // cout<<s<<endl;
        if(root->left)
        f(root->left,s);
        
        if(root->right)
        f(root->right,s);
    }
};