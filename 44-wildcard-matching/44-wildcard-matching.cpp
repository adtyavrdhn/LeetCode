class Solution {
public:
    bool f(int i, int j, string p, string s,vector<vector<int>> &dp)
    {
        // base cases
        if(i==0 && j==0) return true;
        
        if(i==0 && j>0) return false;
        
        if(j==0 && i>0)
        {
            for(int ii=1;ii<=i;ii++)
            {
                if(p[ii-1]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(p[i-1]==s[j-1] || p[i-1]=='?') 
            return dp[i][j]=  f(i-1,j-1,p,s,dp);
        
        if(p[i-1]=='*')
        {
            return dp[i][j] = f(i-1,j,p,s,dp) || f(i,j-1,p,s,dp);
        }
        
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) 
    {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(n+1,vector<bool> (m+1,false));
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 && j==0)
                    dp[i][j]=true;
                
                else if(i==0 && j>0)
                    dp[i][j]=false;
                
                else if(j==0 && i>0)
                {
                    bool flag = true;
                    
                    for(int ii=1;ii<=i;ii++)
                    {
                        if(p[ii-1]!='*')
                        {
                            dp[i][j]=false;
                            flag = false;
                        }
                            
                    }
                    
                    if(flag)
                    dp[i][j]=true;
                }
                
             else if(p[i-1]==s[j-1] || p[i-1]=='?') 
             dp[i][j]=  dp[i-1][j-1];
        
             else if(p[i-1]=='*')
             dp[i][j] = dp[i-1][j] || dp[i][j-1];
        
        
             else dp[i][j] = false;
            }
        }
        
        return dp[n][m];
        // return f(n,m,p,s,dp);
        
    }
};