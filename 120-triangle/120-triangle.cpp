class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) 
    {
        int m = t.size();
        int n = t[m-1].size();
        
        vector<int> next(n,0);
        
        for(int i=0;i<n;i++)
            next[i]=t[m-1][i];
        
        // at any point we only need the previous row
        for(int i=m-2;i>=0;i--)
        {
            vector<int> curr(n,0);
            for(int j=i;j>=0;j--)
            {
               
               int down = t[i][j] + next[j];
               int dio = t[i][j] + next[j+1];
                
               curr[j]=min(down,dio);
            }
            
            next = curr;
        }
        
        return next[0];
        
    }
};