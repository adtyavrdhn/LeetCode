class Solution {
public:
    vector<vector<int>> dir ={{-1,0},{0,-1},{0,1},{1,0}};
    int largestIsland(vector<vector<int>>& grid) 
    {
        int res = 0;
        
        int m = grid.size(), n = grid[0].size();
        
        int id = 2;
        
        bool flag = false;
        
        map<int,int> mpp;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                   int size = dfs(grid,i,j,id);
                   mpp[id]=size;
                   id++;
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    set<int> st;
                    flag = true;
                    
                    for(int k=0;k<4;k++)
                    {
                        int nx = i + dir[k][0];
                        int ny = j + dir[k][1];
                        
                        if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]!=0)
                        {
                            st.insert(grid[nx][ny]);
                        }
                    }
                    
                    int count = 0;
                    
                    for(auto i : st)
                    {
                        count+= mpp[i];
                    }
                    
                    count++;
                    res = max(res,count);
                }
            }
        }
        
        if(!flag)
        {
            return m*n;
        }
        
        return res;
    }
    
    int dfs(vector<vector<int>>&grid, int i, int j, int id)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]!=1)
            return 0;
        
        grid[i][j] = id;
        
       return dfs(grid,i+1,j,id) + dfs(grid,i-1,j,id) + dfs(grid,i,j-1,id) + dfs(grid,i,j+1,id) + 1;
        
    }
};