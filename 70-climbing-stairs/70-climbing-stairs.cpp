class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int> dp={0,1,2,3};
        
        if(n+1 > dp.size())
            dp.reserve(n+1);
        
        for(int i=dp.size();i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        return dp[n];
    }
};