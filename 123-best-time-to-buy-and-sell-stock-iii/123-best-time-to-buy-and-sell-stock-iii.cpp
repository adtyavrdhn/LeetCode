class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (3,-1)));
        return f(prices,0,true,2,dp);
    }
    
    int f(vector<int>& prices, int index, bool buy, int count,vector<vector<vector<int>>>&dp)
    {
        if(count==0) return 0;
        if(index==prices.size())
            return 0;
        
        if(dp[index][buy][count]!=-1) return dp[index][buy][count];
        
        int profit = 0;
        if(buy)
        {
            profit = max((-prices[index]+f(prices,index+1,false,count,dp)),f(prices,index+1,true,count,dp));
        }
        else
        {
            profit = max((prices[index]+f(prices,index+1,true,count-1,dp)),f(prices,index+1,false,count,dp));
        }
        
        return dp[index][buy][count] = profit;
    }
};