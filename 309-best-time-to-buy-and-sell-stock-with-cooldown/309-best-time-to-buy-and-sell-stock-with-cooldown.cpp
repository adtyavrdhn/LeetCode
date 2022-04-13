class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int n = prices.size();
            vector<vector < int>> dp(n + 2, vector<int> (2, 0));

            for (int i = n - 1; i >= 0; i--)
            {
                int profit = 0;
                for (int j = 0; j <= 1; j++)
                {

                    if (j)
                        profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);

                    else
                        profit = max((prices[i] + dp[i + 2][1]), dp[i + 1][0]);

                    dp[i][j] = profit;
                }
            }

            return dp[0][1];
        }
};