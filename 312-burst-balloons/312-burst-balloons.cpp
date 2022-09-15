class Solution {
public:
    int dp[301][301];
    int maxCoins(vector<int>& nums) 
    {
        int n = nums.size();
        
        memset(dp,-1,sizeof(dp));
        
        nums.push_back(1);
        
        nums.insert(nums.begin(),1);
       
        return f(1,n,nums);
    }
    int f(int i, int j,vector<int>&nums)
    {
        if(i>j)
        {
            return 0;
        }
        
        int res = 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        for(int k=i;k<=j;k++)
        {
            int left  = nums[i-1];
            int right = nums[j+1];
            
            int coins = (left*nums[k]*right) + f(i,k-1,nums) + f(k+1,j,nums);
            
            res = max(res,coins);
        }
        
        return dp[i][j] = res;
    }
};