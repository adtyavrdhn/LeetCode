class Solution
{
    public:
        int countSubstrings(string s)
        {
            int n = s.size();
            vector<vector < int>> dp(n, vector<int> (n, 0));
            
            
            int count = 0;
            
            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = n - 1; j >= i; j--)
                {
                    if (i == j)
                    {
                        dp[i][j] = 1;	//base case : only one char
                    }
                    else if (j - i == 1)
                    {
                        if (s[i] == s[j]) dp[i][j] = 1;
                    }
                    else if (s[i] == s[j] && dp[i + 1][j - 1])
                    {
                        dp[i][j] = 1;
                    }

                    count+= dp[i][j];
                }
            }
            return count;
        }
};