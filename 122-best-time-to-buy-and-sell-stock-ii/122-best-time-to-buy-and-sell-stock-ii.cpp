class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int n = prices.size();
            vector<vector < int>> dp(n, vector<int> (2, -1));
            return f(prices, 0, true, dp);
        }

    int f(vector<int> &prices, int index, bool buy, vector<vector< int>> &dp)
    {
        if (index == prices.size())
            return 0;

        int profit = 0;
        
        if(dp[index][buy]!=-1) return dp[index][buy];
        if (buy)
        {
            profit = max((-prices[index] + f(prices, index + 1, false, dp)), f(prices, index + 1, true, dp));
        }
        else
        {
            profit = max((prices[index] + f(prices, index + 1, true, dp)), f(prices, index + 1, false, dp));
        }

        return dp[index][buy] = profit;
    }
};