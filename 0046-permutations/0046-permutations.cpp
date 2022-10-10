class Solution
{
    public:
        vector<vector < int>> res;
    vector<vector < int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> vis(n, false);
        vector<int> temp;
        f(nums,temp,vis);
        
        return res;
    }
    void f(vector<int> &nums, vector<int> &temp, vector< bool > &vis)
    {
        if (temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!vis[i]) 
            {
                vis[i]=true;
                temp.push_back(nums[i]);
                f(nums,temp,vis);
                vis[i]=false;
                temp.pop_back();
            }
        }
    }
};