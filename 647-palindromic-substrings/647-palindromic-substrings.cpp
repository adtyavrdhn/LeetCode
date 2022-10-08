class Solution {
public:
    int dp[1001][1001];
    int countSubstrings(string s)
    {
        int res = 0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                res+= f(s,i,j);
            }
        }
        
        return res;
    }
    int f(string& s, int i, int j)
    {
        if(i>=j)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j] = s[i]==s[j] ? f(s,i+1,j-1) : 0;
    }
};