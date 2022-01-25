class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxarea = 0;
        int area = 0;
        
        int m = grid.size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                    {
                      area = dfs(grid,i,j);
                      maxarea = max(area,maxarea);
                    }
            }
        }
        
        return maxarea;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
       
        if(i < 0 || j< 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j]==0)
            return 0;
        
        grid[i][j]=0;
        
       return dfs(grid,i+1,j) + dfs(grid,i-1,j) + dfs(grid,i,j-1) + dfs(grid,i,j+1) + 1;
        
    }
};