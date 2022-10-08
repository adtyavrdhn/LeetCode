class Solution
{
    public:
        int maximalSquare(vector<vector < char>> &arr)
        {
            int m = arr.size(), n = arr[0].size();
            vector<vector < int>> dp(m+1, vector<int> (n+1, 0));
            
            int res = 0;

            for (int i = m - 1; i >= 0; i--)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    if(arr[i][j]=='1')
                    {
                        dp[i][j] = 1 + min({dp[i + 1][j],dp[i][j + 1],dp[i + 1][j + 1]});
                    }
                    
                    res = max(res,dp[i][j]);
                }
            }
            
            return res*res;
        }
};