class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    
    void dfs(vector<vector<int>>&grid, int i, int j,int k)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]==1 || grid[i][j]==2)
            return;
        
            grid[i][j]=-1;
        
           int ni = i + dir[k][0];
           int nj = j + dir[k][1];
        
        dfs(grid,ni,nj,k);
        
    
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        vector<vector<int>> grid(m, vector<int> (n,0));
        
        for(auto guard : guards)
        {
            grid[guard[0]][guard[1]]=1;
        }
        
        for(auto wall : walls)
        {
            grid[wall[0]][wall[1]]=2;
        }
        
     
        for(auto guard : guards)
        {
            int x = guard[0];
            int y = guard[1];
            
            dfs(grid,x+1,y,1);
            dfs(grid,x-1,y,0);
            dfs(grid,x,y-1,2);
            dfs(grid,x,y+1,3);
        }
        
        int count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    count++;
            }
        }
        
        return count;
    }
};