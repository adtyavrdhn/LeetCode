class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& grid) 
    {
        int m = grid.size(),n = grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            // starting point is grid[0][i]
            
            int x = 0, y = i;
            int num = grid[x][y];
            
            
            while(x<m && y<n)
            {
                x++,y++;
                
                if(x<m && y<n)
                    if(grid[x][y]!=num)
                        return false;
            }
        }
        
        for(int i=0;i<m;i++)
        {
            int x = i, y = 0;
            
            int num = grid[x][y];
            while(x<m && y<n)
            {
                x++,y++;
                
                if(x<m && y<n)
                    if(grid[x][y]!=num)
                        return false;
            }
        }
        
        return true;
    }
};