class Solution
{
    public:
        vector<vector < int>> buildMatrix(int k, vector<vector < int>> &rowConditions, vector< vector< int>> &colConditions)
        {
            vector<int> row = f(rowConditions, k);
            vector<int> col = f(colConditions, k);
            
            if(row.size() < k || col.size() < k)
                return {};
            
            unordered_map<int,int> mppr;
            unordered_map<int,int> mppc;
            
            vector<vector<int>> res(k, vector<int> (k,0));
            
            for(int i=0;i<row.size();i++)
            {
                mppr[row[i]]=i;
            }
            
            for(int i=0;i<col.size();i++)
            {
                mppc[col[i]]=i;
            }
            
            for(int i=1;i<=k;i++)
            {
                res[mppr[i]][mppc[i]]=i;
            }
            
            for(auto i : row)
            {
                cout<<i<<" ";
            }
            cout<<endl;
            
            for(auto i : col)
            {
                cout<<i<<" ";
            }
            
            cout<<endl;
            
            
            return res;
        }

    vector<int> f(vector<vector < int>> &arr, int k)
    {
        vector<int> indeg(k + 1, 0);

        vector<vector < int>> g(k + 1);

        for (int i = 0; i < arr.size(); i++)
        {
            int x = arr[i][0];
            int y = arr[i][1];

            g[x].push_back(y);

            indeg[y]++;
        }

        queue<int> q;

        vector<int> res;

        for (int i = 1; i <= k; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            res.push_back(node);

            for (auto i: g[node])
            {
                indeg[i]--;
                if (indeg[i] == 0)
                {
                    q.push(i);
                }
            }
        }

        return res;
    }
};