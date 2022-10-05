class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<int>> adj[n];
        
        queue<array<int,3>> q;
        
        for(auto i : flights)
        {
            int x = i[0], y = i[1], wt = i[2];
            adj[x].push_back({y,wt});
        }
        
        q.push({src,0,0});
        
        vector<int> dist(n,1e9);
        dist[src] = 0;
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int u = node[0];
            int d = node[1];
            int steps = node[2];
            
            if(steps>k)
                continue;
            
            
            for(auto i : adj[u])
            {
                int v = i[0], distv=i[1];
                
                if(dist[v] > distv+d)
                {
                    dist[v] = distv + d;
                    q.push({v,dist[v],steps+1});
                }
            }
        }
        
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};