class Solution
{
    public:
        vector<int> findBall(vector<vector < int>> &grid)
        {
            int m = grid.size(), n = grid[0].size();

            vector<int> res(n, 0);

            for (int i = 0; i < n; i++)
            {
                res[i] = f(grid, 0, i);	
            }

            return res;
        }
    int f(vector<vector < int>> &grid, int i, int j)
    {
        if(i==grid.size())
            return j;
        
        int nj = j + grid[i][j];
        
        if(nj<0 || nj>=grid[0].size() || grid[i][j]!= grid[i][nj])
            return -1;
        
        
        return f(grid,i+1,nj);
    }
};