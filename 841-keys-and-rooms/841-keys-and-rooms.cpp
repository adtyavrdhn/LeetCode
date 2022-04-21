class Solution
{
    public:
    vector<int> parent;
    bool canVisitAllRooms(vector<vector < int>> &rooms)
    {
        int n = rooms.size();
        parent.resize(n);
        
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
                int x = parent[key];
                if (x!=0)
                {
                    q.push(key);
                }       
            }
                
        }

        for(int i=0;i<parent.size();i++)
        {
            if(parent[i]!=0) return false;
        }
        return true;
    }
};