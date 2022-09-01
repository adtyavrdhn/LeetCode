class Solution
{
    public:
        bool f(vector<vector < int>> &grid, vector< vector< bool>> &vis, int mid, int i, int j)
        {
            if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j] || grid[i][j] > mid)
            {
                return false;
            }
            if (i==grid.size() -1 && j == grid.size()-1) return true;

            vis[i][j] = true;

            return f(grid, vis, mid, i + 1, j) ||
                f(grid, vis, mid, i, j + 1) ||
                f(grid, vis, mid, i - 1, j) ||
                f(grid, vis, mid, i, j - 1);
        }
    int swimInWater(vector<vector < int>> &grid)
    {
        int n = grid.size();

        int low = 1, high = n *n + 1;
        
        if(n==1)
            return 0;

        int res = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            
            vector<vector<bool>> vis(n, vector<bool>(n,false));

            if (f(grid,vis,mid,0,0))
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return res;
    }
};