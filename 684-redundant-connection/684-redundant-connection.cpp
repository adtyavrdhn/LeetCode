class Solution
{
    public:
        int find(int x, vector<int> &parent)
        {
            return x == parent[x] ? x : find(parent[x],parent);
        }
    void unionn(int i, int j, vector<int> &parent, vector<int> &size)
    {
        int x = find(i,parent);
        int y = find(j,parent);

        if (x != y)
        {
            if (size[x] >= size[y])
            {
                parent[y] = x;
                size[x]++;
            }
            else
            {
                parent[x] = y;
                size[y]++;
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector < int>> &edges)
    {
        int n = edges.size();

        vector<int> parent(n+1, 0);
        vector<int> size(n, 1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        for (auto i: edges)
        {
            int x = i[0];
            int y = i[1];

            int px = find(x,parent);
            int py = find(y,parent);

            if (px != py)
            {
                unionn(px, py,parent,size);
            }
            else
            {
                return {x,y};
            }
        }

        return {};
    }
};