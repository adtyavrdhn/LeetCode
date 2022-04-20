class Solution
{
    public:
        int closedIsland(vector<vector < int>> &grid)
        {
            int count = 0;
            int row = grid.size();
            int col = grid[0].size();
            for (int i = 0; i < row; i++)
                dfs(grid, i, 0), dfs(grid, i, col - 1);
            for (int j = 0; j < col; j++)
                dfs(grid, 0, j), dfs(grid, row - 1, j);
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                    if (!grid[i][j])
                        dfs(grid, i, j), count++;
            return count;
        }

    void dfs(vector<vector < int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j])
            return;

        grid[i][j] = 1;

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};