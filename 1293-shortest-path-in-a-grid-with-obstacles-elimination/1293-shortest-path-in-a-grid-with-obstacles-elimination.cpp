class Solution {
public:
    int dp[41][41][1650];
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size(), n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        vector<vector<bool>> vis(m, vector<bool> (n,false));
        int res = f(grid,k,m-1,n-1,vis);
        
        return res >= 1e9 ? -1 : res;
    }
    int f(vector<vector<int>>&grid, int k, int i, int j,vector<vector<bool>>&vis)
    {
        if(i<0 || j<0 || i>= grid.size() || j>= grid[i].size() || k<0 || vis[i][j])
        {
            return 1e9;
        }
        
        if(i==0 && j==0)
        {
            return 0;
        }
        
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        
        if(grid[i][j])
        {
            if(k==0)
                return 1e9;
            
            k--;
        }
        
        vis[i][j] = true;
        
        int left = 1 + f(grid,k,i,j-1,vis);
        int top = 1 + f(grid,k,i-1,j,vis);
        int right = 1 + f(grid,k,i,j+1,vis);
        int down = 1 + f(grid,k,i+1,j,vis);
        
        vis[i][j]=false;
        
        return dp[i][j][k] = min({left,top,right,down});
    }
    
    // ltrd
};