class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        
        vector<int> prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int> curr(n,0);
            
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    curr[j]=grid[i][j];
                else
                {
                     int left = grid[i][j];
                     int up = grid[i][j];
                    
                    if(j>0)
                        left += curr[j-1];
                    else
                        left+=1e9;
                    
                    if(i>0)
                        up+=prev[j];
                    else
                        up+=1e9;
                    
                    
                    curr[j]=min(up,left);
                }
            }
            
            prev = curr;
        }
        
        return prev[n-1];  
    }
};