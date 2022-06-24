class Solution
{
    public:
#define inf 1e9
    int findTheCity(int n, vector<vector < int>> &edges, int dt)
    {
        vector<vector < int>> dist(n, vector<int> (n, inf));

        for (auto i: edges)
        {
            int t = i[0];
            int f = i[1];
            int w = i[2];
            dist[t][f] = w;
            dist[f][t] = w;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    dist[i][j] = 0;
            }
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][j] > (dist[i][k] + dist[k][j]) &&
                        (dist[k][j] != inf &&
                            dist[i][k] != inf))
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        int minc = INT_MAX;
        int res = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int count = 0;

            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] > 0 && dist[i][j] <= dt)
                {
                    count++;
                }
            }
            if (count <= minc)
            {
                minc = count;
                res = i;
            }
        }

       	// for(int i=0;i < n;i++)
       	// {
       	//     for(int j=0;j < n;j++)
       	//     {
       	//         cout<<dist[i][j]<<" ";
       	//     }
       	//     cout<<endl;
       	// }

        return res;
    }
};