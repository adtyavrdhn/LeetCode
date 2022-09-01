#define pi pair<int,int>

class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};
    bool helper(vector<vector<int>>& cells,int mid,int m, int n)
    {
        vector<vector<int>> grid(m, vector<int>(n,0));
        
          for(int i=0;i<mid;i++)
        {
            int x = cells[i][0]-1;
            int y = cells[i][1]-1;
            
            grid[x][y] = 1;
        }
        
        vector<vector<int>> visited(m, vector<int>(n,0));
        
        
        
        queue<pi> q;
        
        for(int i=0;i<n;i++)
        {
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
            
            if(x==m-1) return true;
            
            for(int i=0;i<4;i++)
            {
                int r = x+dir[i][0];
                int c = y+dir[i][1];
                
                if(r>=0 and r<m and c>=0 and c<n)
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
    
    int latestDayToCross(int m, int n, vector<vector<int>>& cells) {
        int s = 1;
        int e = m*n;
        
        
        int ans = 0;
        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(helper(cells, mid,m,n)){
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        
        return ans;
    }
};