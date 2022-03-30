class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = size(nums);
        if(n==1)
            return nums[0];
        
       vector<int> t1;
        vector<int>t2;
        
        for(int i=0;i<n;i++)
        {
            if(i!=0) t1.push_back(nums[i]);
            if(i!=n-1) t2.push_back(nums[i]);
        }
        
        int res1 = helper(t1);
        int res2 = helper(t2);
        
        return max(res1,res2);
       
    }
    
    int helper(vector<int>& nums)
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