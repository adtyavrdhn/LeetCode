class Solution
{
    public:
        vector<int> parent;
    void unionn(int i, int j)
    {
        parent[j] = i;
    }
    int find(int x)
    {
        return x == parent[x] ? x : find(parent[x]);
    }
    int minCostConnectPoints(vector<vector < int>> &points)
    {
        int n = points.size();

        parent.resize(n+1, -1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        vector<pair<int, pair<int, int>>> adj;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                adj.push_back({dist,{i,j}});
            }
        }

        sort(adj.begin(), adj.end());

        int res = 0;

        for (int i = 0; i < adj.size(); i++)
        {
            int x = find(adj[i].second.first);
            int y = find(adj[i].second.second);

            if (x != y)
            {
                res += adj[i].first;
                unionn(x, y);
            }
        }

        return res;
    }
};