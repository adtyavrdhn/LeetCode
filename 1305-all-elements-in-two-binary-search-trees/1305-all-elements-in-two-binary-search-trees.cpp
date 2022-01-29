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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
      vector<int> res;
    stack<TreeNode*> s1,s2;
    
    while(root1||root2|| !s1.empty()||!s2.empty())//when both roots and stacks are not empty
    {
        while(root1!=NULL)//when root-1 is not null, then push root value in stack s1 and go to root's left
        {
            s1.push(root1);
            root1=root1->left;
        }
        while(root2!=NULL)//when root-2 is not null,then push it on stack s2 and move to root's left
        {
            s2.push(root2);
            root2=root2->left;
        }
        if(s2.empty()||(!s1.empty() && s1.top()->val<=s2.top()->val))//if s1 top is less then s2 top means s1 top element is smaller then s2-top element ,
		//then push that value in ans vector and check for it's right
        {
            root1=s1.top();
            s1.pop();
            res.push_back(root1->val);
            root1=root1->right;
        }
        else
        {
            root2=s2.top();
            s2.pop();
            res.push_back(root2->val);
            root2=root2->right;
        }
    }
    return res;
    }
};