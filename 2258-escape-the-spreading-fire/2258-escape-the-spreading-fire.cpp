class Solution {
public:
    #define MAX_T 1e9
    
    struct triplet{  // for storing tripet in queue
        long r,c,t;
    };
    
    vector<vector<int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};
    
    bool isPossible(long maxT,  vector<vector<int>> &fire)
    {
        int m=fire.size();
        int n=fire[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        visited[0][0]=true; // mark start idx as visited
        
        queue<triplet> q;
        q.push({0,0,maxT}); 
        
        while(!q.empty()){
            auto [r,c,t]=q.front();
            q.pop();

            if(r==m-1 && c==n-1)
                return true; // reached home
            
            if(fire[r][c]<=t)  //fire reached to person at same time or before he reached 
                continue;
            
            for(int i=0;i<4; i++)
            {
                int nR = r+dir[i][0]; // new row
                int nC = c+dir[i][1]; // new Col
                
               if(min(nR, nC)>=0 && nR<m && nC<n && fire[nR][nC]!=-1 && t+1 <= fire[nR][nC])
               {
                   if(!visited[nR][nC]){
                       visited[nR][nC]=true; //make it visited
                       q.push({nR, nC, t+1}); // push in queue to check adj
                   }
               }
            }
        }
        
        return false; //cannot reach if waited maxT min at initial pos/no way possibe
    }
    
    int maximumMinutes(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> fire(m, vector<int>(n,INT_MAX));
        
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    fire[i][j]=0;
                    q.push({i,j});
                }
                else if(grid[i][j]==2)
                {
                    fire[i][j]=-1;
                }
            }
        }
        
        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                
                if(nx>=0 && ny>=0 && nx<m && ny<n && fire[nx][ny]!=-1)
                {
                    if(fire[nx][ny]>fire[x][y] + 1)
                    {
                        fire[nx][ny]=fire[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
            
        }
        
         long l=0, h=MAX_T, maxWaitingTime=-1;
        
         while(l<=h)
         {
            long mid=l+(h-l)/2;
            if(isPossible(mid, fire))
            {
                //store the max time till now which is possible
                maxWaitingTime=max(maxWaitingTime,mid);
                // if we can wait this longer then try to wait longer
                l=mid+1;
            }
             else
             {
                //check for waitaing for shorter period instead
                h=mid-1;
            }
        }
        
        return maxWaitingTime;
        
    }
};

// https://leetcode.com/problems/escape-the-spreading-fire/discuss/2126299/C%2B%2B-oror-BFS-%2B-Binary-Search-oror-Explained-with-comments