class Solution
{
    public:
    int dp[21][31];
        bool isMatch(string s, string p)
        {
            memset(dp,-1,sizeof(dp));
            
            return f(0, 0, s, p);
        }
    bool f(int i, int j, string s, string p)
    {
        if(j>=p.size())
        {
            return i>=s.size();
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        bool res = i < s.size() && iseql(s[i], p[j]);

        if (p[j + 1] == '*')
        {
           return dp[i][j] = (res && f(i + 1, j, s, p)) || (f(i, j + 2, s, p));
        }

        return dp[i][j] = res && f(i + 1, j + 1, s, p); // short circuiting to return the answer after checking the first condition 
    }
    bool iseql(char a, char b)
    {
        return (a == b) || b == '.';
    }
};