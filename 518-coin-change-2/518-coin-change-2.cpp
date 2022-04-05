class Solution {
public:
    int change(int target, vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        return f(nums,n-1,target,dp);
    }
    int f(vector<int>&nums , int index, int target,vector<vector<int>> &dp)
    {
        if(target==0) return 1;
        
        
        if(index==0)
        {
            if(target%nums[index]==0)
                return 1;
            else
                return 0;
        }
        
        if(dp[index][target]!=-1) return dp[index][target];
         
        int pick = 0;
        if(nums[index]<=target)
         pick = f(nums,index,target-nums[index],dp);
        
        int npick = f(nums,index-1,target,dp);
        
        return dp[index][target] = (pick+npick);
    }
};