class Solution {
public:
    int mod = 1e9 + 7;
    int base = 1000;
    vector<vector<int>> dp;
    int numberOfWays(int start, int end, int k) 
    {
        dp = vector(4001,vector(1001,-1));
        
        return f(start,end,k);
    }
    int f(int start, int end, int k)
    {
        if(k==0)
        {
           return start==end;
        }
        long long left=0,right=0;
        
        if(dp[start+base][k]!=-1)
            return dp[start+base][k];
        
        left+= f(start-1,end,k-1) % mod;
        right+= f(start+1,end,k-1) % mod;
        
        return dp[start+base][k] = (left+right)%mod;
        
        // return dp[start][end][k] = (left+right)%mod;
    }
};