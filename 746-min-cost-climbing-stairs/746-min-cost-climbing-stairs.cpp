class Solution {
public:
    vector<int> dp;
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        dp.resize(n+1,-1);
        
        return min(f(cost,n,0),f(cost,n,1));
    }
    int f(vector<int>&cost, int n, int i)
    {
        if(i>=n)
            return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int one = cost[i] + f(cost,n,i+1);
        
        int two = cost[i] + f(cost,n,i+2);
        
        
        return dp[i] = min(one,two);
    }
};