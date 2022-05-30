class Solution
{
    public:
    int minimumObstacles(vector<vector < int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector <int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};
        vector<vector <int>> dp(n, vector<int> (m, INT_MAX));
      

        queue<pair<int,int>> q;
        
        q.push({0,0});
        dp[0][0]=0;
        
        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                pair<int, int> node = q.front();

                int x = node.first;
                int y = node.second;
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dir[k][0];
                    int ny = y + dir[k][1];

                    if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size())
                    {
                        if (grid[x][y] + dp[x][y] < dp[nx][ny])
                        {
                            dp[nx][ny] = grid[x][y] + dp[x][y];
                            q.push({nx,ny});
                        }
                            
                    }
                }
            }
        }
     return dp[n-1][m-1];
    }
};