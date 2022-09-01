#define pi pair<int,int>

class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};
    bool helper(vector<vector<int>>& grid){
       
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        
        
        
        queue<pi> q;
        
        for(int i=0;i<m;i++){
            if(grid[0][i]==0){
                q.push({0,i});
                visited[0][i] = 1;
            }
        }
        
        if(q.size()==0) return false;
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(x==n-1) return true;
            
            for(int i=0;i<4;i++)
            {
                int r = x+dir[i][0];
                int c = y+dir[i][1];
                
                if(r>=0 and r<n and c>=0 and c<m)
                {
                    if(!visited[r][c] and grid[r][c]==0)
                    {
                        visited[r][c]=1;
                        q.push({r,c});
                    }
                }
            }
        }
        
        return false;
    }
    
    
    
    bool isPossibleToCross(vector<vector<int>>& grid, vector<vector<int>>& cells, int mid){
       
        for(int i=0;i<mid;i++)
        {
            int x = cells[i][0]-1;
            int y = cells[i][1]-1;
            
            grid[x][y] = 1;
        }
        
        bool res = helper(grid);
        
        for(int i=0;i<mid;i++)
        {
            int x = cells[i][0]-1;
            int y = cells[i][1]-1;
            
            grid[x][y] = 0;
        }
        
        if(res) return true;
        
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int s = 1;
        int e = row*col;
        vector<vector<int>> grid(row, vector<int>(col,0));
        
        int ans = 0;
        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(isPossibleToCross(grid, cells, mid)){
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        
        return ans;
    }
};