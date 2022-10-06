class Solution
{
    public:
        int numDistinct(string s, string t)
        {
            int m = s.size(), n = t.size();

            vector<vector < double>> dp(m + 1, vector<double> (n + 1, 0));

            for (int i = 0; i <= m; i++)
            {
                dp[i][n] = 1;
            }

            for (int i = m - 1; i >= 0; i--)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    double match = 0;
                    if (s[i] == t[j])
                    {
                        match = dp[i + 1][j + 1];
                    }

                    double nmatch = dp[i + 1][j];
                    
                    dp[i][j] =  match+nmatch;
                }
            }
            
            return dp[0][0];
        }
};