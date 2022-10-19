class Solution
{
    public:
        int dp[201][201];
    int minFallingPathSum(vector<vector < int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        memset(dp, -1, sizeof(dp));
        int res = INT_MAX;
        
        if(n==1)
            return grid[0][0];

        for (int i = 0; i < n; i++)
        {
            res = min(res, f(grid, 0, i));
        }

        return res;
    }
    int f(vector<vector < int>> &grid, int i, int j)
    {
        if (i >= grid.size())
        {
            return 0;
        }
        if (j < 0 || j >= grid[0].size())
        {
            return 1e9;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int res = 1e9;

        for (int k = 0; k < grid[0].size(); k++)
        {
            if (k != j)
            {
                res = min(res, grid[i][j]+f(grid,i+1,k));
            }
        }

        return dp[i][j] = res;
    }
};