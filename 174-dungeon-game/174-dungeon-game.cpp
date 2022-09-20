class Solution
{
    public:
        int calculateMinimumHP(vector<vector < int>> &arr)
        {
            int m = arr.size(), n = arr[0].size();

            vector<vector < int>> dp(m + 1, vector<int> (n + 1, 0));

            for (int i = 0; i <= m; i++)
            {
                dp[i][n] = 1e9;
            }

            for (int i = 0; i <= n; i++)
            {
                dp[m][i] = 1e9;
            }

            dp[m - 1][n - 1] = arr[m - 1][n - 1] > 0 ? 1 : 1 - arr[m - 1][n - 1];

            for (int i = m - 1; i >= 0; i--)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    if(i==m-1 && j == n-1)
                        continue;
                    
                    int res = 0;

                    int right = dp[i][j + 1];
                    int down = dp[i + 1][j];

                    res = min(down, right) - arr[i][j];

                    dp[i][j] = res > 0 ? res : 1;
                }
            }
            
            return dp[0][0];
        }
};