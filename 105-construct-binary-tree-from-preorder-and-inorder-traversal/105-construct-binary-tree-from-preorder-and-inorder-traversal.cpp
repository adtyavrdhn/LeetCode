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
        TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
        {
            map<int, int> mpp;

            for (int i = 0; i < inorder.size(); i++)
            {
                mpp[inorder[i]] = i;
            }

            TreeNode *root = f(0, preorder.size() - 1, preorder, 0, inorder.size() - 1, inorder, mpp);
            
            return root;
        }
    TreeNode* f(int prestart, int preend, vector<int> &preorder, int instart, int inend, vector<int> &inorder, map< int, int> &mpp) 
    {
        if(prestart > preend || instart > inend)
        {
            return NULL; //attaching a NULL to the tree if no elements are present in this subtree
        }
        
        TreeNode* root = new TreeNode(preorder[prestart]); // the current node is always at preorder's start, now we'll need to recursively build the left and right subtrees
        
        int inroot = mpp[root->val];
        
        int numsleft = inroot-instart; // nums in the left subtree
        
        root->left = f(prestart+1,prestart+numsleft,preorder,instart,inroot-1,inorder,mpp);
        root->right = f(prestart+numsleft+1,preend,preorder,inroot+1,inend,inorder,mpp);
        
        return root;
    }
};