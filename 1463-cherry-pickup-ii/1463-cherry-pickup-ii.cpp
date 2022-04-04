class Solution {
public:
       int dy[3]={0, -1, 1};
       int dp[71][71][71];
       int dfs(vector<vector<int>> &grid,int i,int c1,int c2) 
       {
          
        if(c1<0||c1>=grid[0].size()||c2<0||c2>=grid[0].size()) return -1e9;
           
        if(i==grid.size()-1)
        {
            if(c1!=c2)return grid[i][c1]+grid[i][c2];
            return grid[i][c1];
        }
           
        if(dp[i][c1][c2]!=-1) return dp[i][c1][c2];
           
          int maxi=0;
       
        for(int k=0; k<3; k++)
        {
            for(int r=0; r<3; r++)
            {
                int value=0;
                value= (c1==c2)? grid[i][c1]: grid[i][c1] + grid[i][c2];
                
                 value+= dfs(grid,i+1,c1+dy[k],c2+dy[r]); 
                maxi=max(maxi,value);
            }
        }
    
         return dp[i][c1][c2] =maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) 
    {
        memset(dp,-1,sizeof dp);
        return dfs(grid,0,0,grid[0].size()-1);  
    }
};