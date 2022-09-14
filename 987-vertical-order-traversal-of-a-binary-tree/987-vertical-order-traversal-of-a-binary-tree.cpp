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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // column -> row -> values at that x and y position
        
        map<int,map<int,multiset<int>>> nodes;
        
        f(root,0,0,nodes);
        
        vector<vector<int>> res;
        
        // for each column
        for(auto i : nodes)
        {
            vector<int> column;
            
            // for each row in that column
            for(auto j : i.second)
            {
                column.insert(column.end(),j.second.begin(),j.second.end());
            }
            res.push_back(column);
        }
        
        return res;  
    }
    void f(TreeNode *root, int col, int row,map<int,map<int,multiset<int>>>&mpp)
    {
        if (!root)
        {
            return;
        }
        mpp[col][row].insert(root->val);

        f(root->left, col - 1, row + 1,mpp);
        f(root->right, col + 1, row + 1,mpp);
    }
};