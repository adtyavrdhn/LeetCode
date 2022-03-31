class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) 
    {
        int m = g.size();
        int n = g[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,g,dp);
    }
    int f(int i,int j, vector<vector<int>>& g,vector<vector<int>> &dp)
    {
        if(i==0 && j==0 && g[i][j]==1) return 0;
        if(i==0 && j==0 && g[i][j]==0) return 1;
        if(i<0 || j<0 ||g[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up = f(i-1,j,g,dp);
        int left = f(i,j-1,g,dp);
        
        return dp[i][j]=left+up;
    }
};