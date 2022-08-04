class Solution
{
    public:
        int networkDelayTime(vector<vector < int>> &edges, int n, int k)
        {
            vector<int> keys(n + 1, INT_MAX);

            keys[k] = 0;

            vector<vector<int>> g(n+1, vector<int> (n+1, -1));
            unordered_map<int,bool> vis;

            for (int i = 0; i < edges.size(); i++)
            {
                int x = edges[i][0];
                int y = edges[i][1];
                int wt = edges[i][2];

                g[x][y] = wt;
            }

            for (int i = 0; i < n - 1; i++)
            {

                int u = 0;

                int minkey = INT_MAX;
                for (int j = 1; j <= n; j++)
                {
                    if (keys[j] < minkey && !vis[j])
                    {
                        u = j;
                        minkey = keys[j];
                    }
                }
                
                vis[u]=true;

                for (int v = 1; v <= n; v++)
                {
                    if (g[u][v] >= 0)
                    {
                         keys[v] = min(keys[v], keys[u] + g[u][v]);
                    }
                       
                }
            }

//             for(int i=1;i<=n;i++)
//             {
//                 cout<<keys[i]<<" ";
//             }
            
//             cout<<endl;
            
            int res = 0;
            for(int i=1;i<=n;i++)
            {
                res = max(res, keys[i]);
            }

            return res == INT_MAX ? -1 : res;
        }
};