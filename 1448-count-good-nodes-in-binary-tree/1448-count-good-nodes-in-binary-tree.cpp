/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
    int count = 0;
        int goodNodes(TreeNode *root)
        {
            f(root, root->val);
            
            return count;
        }
    void f(TreeNode *root, int val)
    {
        if (!root)
            return;

       f(root->left, max(val,root->val));
        
        if(root->val >= val)
            count++;

        f(root->right, max(val,root->val));
    }
};