class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        queue<array<int,3>> pq;
        
        pq.push({0,src,0});
        
        vector<int> dist(n,1e9);
        dist[src] = 0;
        vector<vector<int>> adj[n];
        
        
        for(auto i : flights)
        {
            int x = i[0], y = i[1], wt = i[2];
            
            adj[x].push_back({y,wt});
        }
        
        while(!pq.empty())
        {
            auto node = pq.front();
            pq.pop();
            
            int u = node[1];
            int steps = node[2];
            int d = node[0];
            
            if(steps>k)
                continue;
            
            for(auto i : adj[u])
            {
                int v = i[0];
                int wt = i[1];
                
                if(dist[v] > wt+d && steps<=k)
                {
                    dist[v] = wt+d;
                    pq.push({dist[v],v,steps+1});
                    
                }
            }
        }
        
        if(dist[dst]==1e9)
            return -1;
        
        return dist[dst];
    }
};