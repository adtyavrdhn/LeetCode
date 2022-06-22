class Solution
{
    public:
        int maxSumDivThree(vector<int> &nums)
        {
            vector<vector<int>> dp(nums.size()+1, vector<int> (4,-1));
            return f(nums, 0,0,dp);
        }

    int f(vector<int> &nums, int index, int ctake,vector<vector<int>> &dp)
    {
        if (index == nums.size())
        {
           if(ctake == 0)
           {
               return 0;
           }
            else return INT_MIN;
        }
        
        if(dp[index][ctake]!=-1)
        {
            return dp[index][ctake];
        }

        int take = nums[index] + f(nums, index + 1, (nums[index]+ctake)%3,dp);
        int ntake = f(nums, index + 1,ctake,dp);

        return dp[index][ctake]=max(take, ntake);
    }
};