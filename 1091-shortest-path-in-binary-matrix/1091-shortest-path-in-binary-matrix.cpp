class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        
       int m = grid.size();
       int n = grid[0].size();
        
        
      if(grid[0][0]==1 || grid[m-1][n-1]==1) return -1;
        
       queue<pair<int,int>> q;
       q.push({0,0});
       
        int count = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            count++;
            for(int i=0;i<size;i++)
            {
                pair<int,int> node = q.front();
                q.pop();
                
                
                int x = node.first;
                int y = node.second;
                
                if(x==m-1 && y==n-1)
                {
                    return count;
                }
                
                for(int i=0;i<8;i++)
                {
                    int nx = x + dir[i][0];
                    int ny = y + dir[i][1];
                    
                    if(nx<0 || ny<0 || nx>=m || ny>= n || grid[nx][ny]==1)
                        continue;
                    
                    grid[nx][ny]=1;
                    q.push({nx,ny});
                }
                
            }
        }
        
        
        return -1;
    }
};