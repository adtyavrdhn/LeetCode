class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min(f(cost,0,dp),f(cost,1,dp));
    }
    int f(vector<int>&cost, int index,vector<int>&dp)
    {
        if(index>=cost.size())
        {
            return 0;
        }
        
        if(dp[index]!=-1)
            return dp[index];
        
        int one = cost[index] + f(cost,index+1,dp);
        int two = cost[index] + f(cost, index+2,dp);
        
        return dp[index] = min(one,two);
    }
};