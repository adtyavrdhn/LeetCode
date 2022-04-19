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
    ////// basic brute force way, storing in an array,sorting it and checking again whereever it doesn't match change it
      void dfs(TreeNode* root, vector<int>& cheat) {
        if(!root) return;
        
        dfs(root->left, cheat);
        cheat.push_back(root->val);
        dfs(root->right, cheat);
    }
    
    void cheatAgain(TreeNode* root, vector<int>& cheat, int& i) {
        if(!root) return;
        cheatAgain(root->left, cheat, i);
        if(root->val != cheat[i]) {
            root->val = cheat[i];
        }
        i++;
        cheatAgain(root->right, cheat, i);
        
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> cheat;
        dfs(root, cheat);
        sort(cheat.begin(), cheat.end());
        int i = 0;
        cheatAgain(root, cheat, i);
        return;
        
    }
};