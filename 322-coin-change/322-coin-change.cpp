class Solution {
public:
    int res = 0;
    int coinChange(vector<int>& coins, int target) 
    {
        if(target==0) return 0;
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(target+1,-1));
        res = f(coins,target,n-1,dp);
        
        if(res == 1e9) return -1;
        
        
        return res;
    }
    
    int f(vector<int> &coins, int target, int index,vector<vector<int>> &dp)
    {
        // if(target==0) return 1;
        
        if(index==0)
        {
            if(target%coins[index]==0) return target/coins[index];
            else
                return 1e9;
        }
        
        if(dp[index][target]!=-1) return dp[index][target];
        int npick = f(coins,target,index-1,dp);
        
        int pick = 1e9;
        if(coins[index]<=target)
        {
            pick = 1 + f(coins,target-coins[index],index,dp);
        }
        
        res =  min(pick,npick);
        
        return dp[index][target]=res;
    }
};