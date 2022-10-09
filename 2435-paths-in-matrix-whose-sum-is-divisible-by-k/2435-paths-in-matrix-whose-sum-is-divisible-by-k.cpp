#define ll long long 
class Solution {
public:
    int mod = (int)1e9+7;
    int numberOfPaths(vector<vector<int>>& grid, int k) 
    {
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                grid[i][j]=grid[i][j]%k;
            }
        }
        
        vector<vector<vector<ll>>> dp(m+1 , vector<vector<ll>>(n+1 , vector<ll>(51 , -1)));
        
        return f(grid,k,0,0,0,dp);
    }
    int f(vector<vector<int>>&grid, int k, int i, int j, long long int sum,vector<vector<vector<ll>>> &dp)
    {
        if(i>=grid.size() || j>=grid[i].size())
        {
            return 0;
        }
        
        if(i==grid.size()-1 && j==grid[i].size()-1)
        {
            return (grid[i][j]+sum)%k==0;
        }
        
        if(dp[i][j][sum]!=-1)
            return dp[i][j][sum];

        int down = f(grid,k,i+1,j,(sum+grid[i][j])%k,dp) % mod;
        int right = f(grid,k,i,j+1,(sum+grid[i][j])%k,dp) %mod;
        
        return dp[i][j][sum] = (down+right)%mod;
    }
};