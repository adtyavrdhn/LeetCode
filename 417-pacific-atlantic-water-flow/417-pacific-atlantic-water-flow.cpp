class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pac(m, vector<bool> (n, false));
        vector<vector<bool>> atl(m, vector<bool> (n,false));
        
        for(int i=0;i<m;i++)
        {
            f(pac,i,0,INT_MIN,heights);
            f(atl,i,n-1,INT_MIN,heights);
        }
        for(int i=0;i<n;i++)
        {
            f(pac,0,i,INT_MIN,heights);
            f(atl,m-1,i,INT_MIN,heights);
        }
        
        int count = 0;
        
        vector<vector<int>> res;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pac[i][j] && atl[i][j])
                    res.push_back({i,j});
            }
        }
        
        return res;
        
    }
    void f(vector<vector<bool>>&ocean, int i, int j, int prev,vector<vector<int>>& heights)
    {
        if(i<0 || j<0 || i>= ocean.size() || j>=ocean[i].size() || ocean[i][j] || heights[i][j]<prev)
            return;
        
        ocean[i][j]=true;
        
        f(ocean,i+1,j,heights[i][j],heights);
        f(ocean, i-1,j,heights[i][j],heights);
        f(ocean,i,j+1,heights[i][j],heights);
        f(ocean,i,j-1,heights[i][j],heights);
    }
};