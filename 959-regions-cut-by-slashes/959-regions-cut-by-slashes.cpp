class Solution
{
    public:
        vector<int> parent;
    vector<int> rank;
    int res = 0;
    int find(int x)
    {
        return x == parent[x] ? x : find(parent[x]);
    }
    void unionn(int i, int j)
    {
        int x = find(i);
        int y = find(j);

        if (x == y)
        {
            res++;
            return;
        }
        if (rank[x] > rank[y])
        {
            parent[y] = x;
            rank[x]++;
        }
        else
        {
            parent[x] = y;
            rank[y]++;
        }
    }
    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();

        int d = n + 1;

        parent.resize(d *d, 0);
        rank.resize(d *d, 1);

        for (int i = 0; i < d * d; i++)
        {
            parent[i] = i;
        }

       	// conencting the outer square for the points

        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                if (i == 0 || j == 0 || i == d - 1 || j == d - 1)
                {

                    int cell = i *d + j;

                    unionn(0, cell);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '/')
                {
                    int x = i *d + (j + 1);
                    int y = ((i + 1) *d) + j;

                    unionn(x, y);
                }
                else if (grid[i][j] == '\\')
                {
                    int x = (i *d) + j;
                    int y = ((i + 1) *d) + (j + 1);

                    unionn(x, y);
                }
            }
        }
        return res;
    }
};