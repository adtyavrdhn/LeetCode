class Solution {
public:
    int minDistance(string s, string t) 
    {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(s,t,m-1,n-1,dp);
    }
    
    int f(string s, string t, int i, int j,vector<vector<int>> &dp)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]) return dp[i][j] = f(s,t,i-1,j-1,dp);
        
            int in =  f(s,t,i,j-1,dp);
            int rep = f(s,t,i-1,j-1,dp);
            int del = f(s,t,i-1,j,dp);
        
            return dp[i][j] = 1 + min({in,rep,del});
     
    }
};