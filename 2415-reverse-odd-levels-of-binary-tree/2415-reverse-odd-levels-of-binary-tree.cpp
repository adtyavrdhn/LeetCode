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
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        
        stack<int> st;
        
        int level = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
               auto node = q.front();
               q.pop();
                
               if(level%2==0)
               {
                   if(node->left)
                   {
                       q.push(node->left);
                       st.push(node->left->val);
                   }
                   if(node->right)
                   {
                       q.push(node->right);
                       st.push(node->right->val);
                   }
               }
               else
               {
                    node->val = st.top();
                    st.pop();
                   
                   if(node->left)
                   {
                       q.push(node->left);
                   }
                   if(node->right)
                   {
                       q.push(node->right);
                   }
               }
            }
            level++;
        }
        
        return root;
    }
};