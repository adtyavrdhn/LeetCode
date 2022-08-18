class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int> dp(n,-1);
        
        return f(n,0,dp);
    }
    int f(int n, int i,vector<int>&dp)
    {
        if(i==n)
        {
            return 1;
        }
        
        if(i>n)
        {
            return 0;
        }
        
        if(dp[i]!=-1)
            return dp[i];
        
        int one = f(n,i+1,dp);
        int two = f(n,i+2,dp);
        
        return dp[i] = one + two;
    }
};