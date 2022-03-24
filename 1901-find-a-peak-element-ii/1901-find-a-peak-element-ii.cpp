class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
        int r = mat.size();
        int c = mat[0].size();
        
        int i=0,j=0;
        
        while(i>=0 && i<r && j>=0 && j<c)
        {
            int x = (i-1 <0)?-1:mat[i-1][j];
            int y = (j-1 <0)?-1:mat[i][j-1];
            int z = (j+1==c)?-1:mat[i][j+1];
            int w = (i+1==r)?-1:mat[i+1][j];
            
            if(mat[i][j]>x && mat[i][j]>y && mat[i][j]>z && mat[i][j]>w)
                return {i,j};
            
             int p = max({x,y,z,w});
            
            if(p==x)
                i--;
            else if(p==y)
                j--;
            else if(p==w)
                i++;
            else
                j++;
        }
        
        return {};
    }
};