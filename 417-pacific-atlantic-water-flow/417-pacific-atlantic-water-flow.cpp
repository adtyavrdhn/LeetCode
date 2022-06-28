class Solution
{
    public:
        vector<vector < int>> pacificAtlantic(vector<vector < int>> &heights)
        {
            vector<vector < int>> res;

            if (!heights.size())
                return res;

            int row = heights.size();
            int col = heights[0].size();

            vector<vector < bool>> atlantic(row, vector<bool> (col, false));
            vector<vector < bool>> pacific(row, vector<bool> (col, false));

            for (int i = 0; i < row; i++)
            {
                dfs(heights, i, 0, INT_MIN, pacific);
                dfs(heights, i, col - 1, INT_MIN, atlantic);
            }

            for (int j = 0; j < col; j++)
            {
                dfs(heights, 0, j, INT_MIN, pacific);
                dfs(heights, row - 1, j, INT_MIN, atlantic);
            }

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (pacific[i][j] && atlantic[i][j])
                        res.push_back({ i,
                            j });
                }
            }

            return res;
        }

    void dfs(vector<vector < int>> &matrix, int x, int y, int prev, vector< vector< bool>> &ocean)
    {
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size())
            return;

        if (ocean[x][y])
            return;

        if (matrix[x][y] < prev)
            return;

        ocean[x][y] = true;

        dfs(matrix, x + 1, y, matrix[x][y], ocean);
        dfs(matrix, x - 1, y, matrix[x][y], ocean);
        dfs(matrix, x, y + 1, matrix[x][y], ocean);
        dfs(matrix, x, y - 1, matrix[x][y], ocean);
    }
};