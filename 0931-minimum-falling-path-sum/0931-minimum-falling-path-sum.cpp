class Solution
{
    public:
    int dp[101][101];
        int minFallingPathSum(vector<vector < int>> &grid)
        {
            int m = grid.size();
            int n = grid[0].size();

            memset(dp,-1,sizeof(dp));
            int res = INT_MAX;

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
        
        if(dp[i][j]!=-1)
            return dp[i][j];

        int left = grid[i][j] + f(grid, i + 1, j - 1);
        int right = grid[i][j] + f(grid, i + 1, j + 1);
        int down = grid[i][j] + f(grid, i + 1, j);

        return dp[i][j] = min({left,down,right});
    }
};