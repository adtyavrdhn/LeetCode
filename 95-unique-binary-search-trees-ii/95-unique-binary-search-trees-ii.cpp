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
        vector<TreeNode*> generateTrees(int n)
        {
            return f(1, n);
        }
    vector<TreeNode*> f(int start, int end)
    {
        vector<TreeNode*> res;
        if (start > end)
        {
            res.push_back(nullptr);	// no node
            return res;
        }
        else if (start == end)
        {
            res.push_back(new TreeNode(start));	// only one node
            return res;
        }
        else
        {

            for (int i = start; i <= end; i++)
            {
                auto left = f(start, i - 1);
                auto right = f(i + 1, end);

               	// if i is the root, left will give roots of all the left subtrees which can be formed and so will right

               	// now we can combine these subtrees

                for (auto l: left)
                {
                    for (auto r: right)
                    {
                        auto node = new TreeNode(i);	// root
                        node->left = l;
                        node->right = r;
                        res.push_back(node);
                    }
                }
            }
        }

        return res;
    }
};