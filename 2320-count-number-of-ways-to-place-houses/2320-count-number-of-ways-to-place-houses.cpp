class Solution {
public:
    int mod = 1e9+7;
    
    int countHousePlacements(int n) 
    {
        vector<vector<long long>> dp(n+1, vector<long long> (3,-1));
        
        long long res = f(n,0,true,dp)%mod;
        res = (res%mod * res%mod)%mod;
        
        res%= mod;
        
        return res;
    }
    
    int f(int n, int index, bool ctake,vector<vector<long long>>& dp)
    {
        if(index == n)
        {
           return 1;
        }
        
        if(dp[index][ctake]!=-1)
        {
            return dp[index][ctake];
        }
        
        long long sum = 0;
        if(ctake)
        {
            sum = (sum + f(n,index+1,false,dp)%mod)%mod;
        }
        
        sum = (sum +  f(n,index+1,true,dp)%mod)%mod;
        
        return dp[index][ctake] = sum;
    }
};