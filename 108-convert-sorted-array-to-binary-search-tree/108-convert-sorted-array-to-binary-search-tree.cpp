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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return f(nums,0,nums.size()-1);
    }
    TreeNode* f(vector<int>&nums, int l, int r)
    {
        if(l > r)
        {
            return nullptr;
        }
        
        int mid = (l+r)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        TreeNode* left = f(nums,l,mid-1);
        TreeNode* right = f(nums,mid+1,r);
        
        root->left = left;
        root->right = right;
        
        return root;
    }
    
};