class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        queue<vector<int>> q;
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> obs(m, vector<int>(n,0));
        vector<vector<bool>> vis(m, vector<bool> (n,false));
        
        vis[0][0]=true;
        obs[0][0]=grid[0][0];
        
        
        q.push({0,0,grid[0][0]});
        
        int level = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                auto node = q.front();
                q.pop();
                
                
                if(node[0]==m-1 && node[1]==n-1)
                {
                    return level; 
                }
                
                for(auto t : dir)
                {
                    int nx = node[0] + t[0];
                    int ny = node[1] + t[1];
                    
                     if(nx<0 || ny<0 || nx>=grid.size() || ny>=grid[0].size())
                    {
                       continue;
                    }
                    
                    int o = obs[nx][ny];
                    
                    int no = node[2] + grid[nx][ny];
                    
                    if(!vis[nx][ny] && (no <= k))
                    {
                        q.push({nx,ny,no});
                        obs[nx][ny]=no;
                        vis[nx][ny]=true;
                    }
                    
                    if(o > no && (no <= k))
                     {
                        q.push({nx,ny,no});
                        obs[nx][ny]=no;
                        vis[nx][ny]=true;
                     }
                }
            }
            
            level++;
        }
        
        return -1;
    }
};