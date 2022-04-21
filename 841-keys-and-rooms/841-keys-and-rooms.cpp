class Solution
{
    public:
        vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        return parent[x] == x ? x : find(parent[x]);
    }

    void union_op(int i, int j)
    {
        int x = find(i);
        int y = find(j);

        if (x != y)
        {
            if (rank[x] >= rank[y])
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
    }

    bool canVisitAllRooms(vector<vector < int>> &rooms)
    {
        int n = rooms.size();
        parent.resize(n);
        rank.resize(n,1);
        
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            int i = q.front();
            q.pop();

            if (i!= 0 && parent[i]==0)
                continue;

            parent[i] = 0;

            for (int key: rooms[i])
            {
                int x = find(key);
                if (x!=0)
                {
                    q.push(key);
                }       
            }
                
        }

        for(int i=0;i<parent.size();i++)
        {
            if(parent[i]!=0)return false;
              // cout<<parent[i]<<" ";
        }
        return true;
    }
};