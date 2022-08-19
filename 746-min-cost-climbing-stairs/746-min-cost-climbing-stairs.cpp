class Solution {
public:
    vector<int> dp;
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        dp.resize(n,-1);
        return min(f(cost,0),f(cost,1));
    }
    int f(vector<int>&cost, int i)
    {
        if(i>=cost.size())
        {
            return 0;
        }
        
        if(dp[i]!=-1) return dp[i];
        
        int one = cost[i] + f(cost,i+1);
        int two = cost[i] + f(cost,i+2);
        
        return dp[i] = min(one,two);
    }
};