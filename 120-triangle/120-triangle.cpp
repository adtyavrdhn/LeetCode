class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) 
    {
        int m = t.size();
        int n = t[m-1].size();
        
        vector<vector<int>> dp(m , vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        {
            dp[m-1][i]=t[m-1][i];
        }
        
        for(int i=m-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
               
               int down = t[i][j] + dp[i+1][j];
               int dio = t[i][j] + dp[i+1][j+1];
                
               dp[i][j]=min(down,dio);
            }
        }
        
        return dp[0][0];
        
    }
};