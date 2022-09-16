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
    int res = 0;
    int minCameraCover(TreeNode* root) 
    {
       string node = f(root);
        
        if(node=="want")
            res++;
        
        return res;
    }
    string f(TreeNode* root)
    {
        if(!root)
        {
            return "ok";
        }
        
        string left = f(root->left);
        string right = f(root->right);
        
        if(left=="want" || right=="want")
        {
            // if either children needs a camera, the parent will provide one
            res++;
            return "provide"; // this node is providing for its parents as well as children
        }
        else if(left=="provide" || right=="provide")
            return "ok";
        
        return "want";
        
    }
};