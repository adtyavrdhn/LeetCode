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
    vector<int> t;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        inorder(root1);
        inorder(root2);
        sort(t.begin(),t.end());
        
        return t;
    }
    
    void inorder(TreeNode* r)
    {
     if(r)
     {
        inorder(r->left);
        t.push_back(r->val);
        inorder(r->right);
         
     }
    }
};