class Solution
{
    public:
       	vector<vector<int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};
        int numIslands(vector<vector < char>> &grid)
        {
            int m = grid.size();
            int n = grid[0].size();
            queue<pair<int, int>> q;
            int count = 0;
            
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[i].size(); j++)
                {
                    if (grid[i][j] == '1')
                    {
                        count++;
                        pair<int, int> temp = make_pair(i, j);
                        q.push(temp);
                        grid[i][j]='0';
                        while (!q.empty())
                        {
                            for (int i = 0; i < q.size(); i++)
                            {
                                temp = q.front();
                                q.pop();

                                int r = temp.first;
                                int c = temp.second;
                             
                                for (auto &d: dir)
                                {
                                    int nr = r + d[0];
                                    int nc = c + d[1];

                                    if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == '1')
                                    {
                                        temp = make_pair(nr, nc);
                                        grid[nr][nc]='0';
                                        q.push(temp);
                                    }
                                }
                            }
                        }

                    }
                }
            }

            return count;
        }
};