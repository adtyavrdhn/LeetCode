class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        int res = 0;
        queue<pair<int,int>> q;
            
        int fresh_oranges=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                {
                    fresh_oranges++;
                }
            }
        }
        
        int count=0;
        int time = 0;
        
        while(!q.empty())
        {
            
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
               pair<int,int> rotten_orange = q.front();
               q.pop();
                
               
               int x = rotten_orange.first;
               int y = rotten_orange.second;
                
                for(int j=0;j<4;j++)
                {
                    int nx = x + dir[j][0];
                    int ny = y + dir[j][1];
                    
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1)
                    {
                     fresh_oranges--;
                     grid[nx][ny]=2; // making it rotten
                     q.push({nx,ny});
                    }
                    // every fresh orange that goes bad, we count. It should be total to the fresh_oranges for the bfs to be valid at which point we will return the time elapsed that we count at each level
                    
                }
                
            }
            
            if(!q.empty())
            time++;
        }
        // cout<<fresh_oranges<<" "<<count;
       return fresh_oranges == 0 ? time : -1;
    }
};