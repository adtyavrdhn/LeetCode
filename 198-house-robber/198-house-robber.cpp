class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = size(nums);
        vector<int> dp(n,0);
        
        dp[0]=nums[0];
        
        for(int i=1;i<n;i++)
        {
           int take = nums[i];
            if(i>1) take+=dp[i-2];
            
            int dont = dp[i-1];
            
            dp[i] = max(take,dont);
        }
        
        return dp[n-1];
    }
};