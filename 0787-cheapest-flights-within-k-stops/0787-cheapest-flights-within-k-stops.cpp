class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<int>> g[n];
        
        for(auto i : flights)
        {
            int x = i[0], y = i[1], wt = i[2];
            
            g[x].push_back({y,wt});
        }
        
        vector<int> dist(n,1e9);
        dist[src]=0;
        
        queue<array<int,3>> q;
        
        q.push({src,0,0});
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int u = node[0],steps = node[2],d=node[1];
            
            if(steps>k)
                continue; 
            
            
            for(auto i : g[u])
            {
                int v = i[0], distv = i[1];
                
                if(dist[v] > d + distv)
                {
                    dist[v] = d + distv;
                    q.push({v,dist[v],steps+1});
                }
            }
        }
        
        return dist[dst]==1e9 ? -1 : dist[dst];
    }
};