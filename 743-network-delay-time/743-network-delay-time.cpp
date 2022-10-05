class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        priority_queue<array<int,2>,vector< array<int,2>>,greater< array<int,2>>> pq;
        
        pq.push({0,k});
        
        int res = 0;
        
        vector<vector<int>> adj[n+1];
        
        for(auto i : times)
        {
            int x = i[0], y = i[1], wt = i[2];
            adj[x].push_back({y,wt});
        }
        
        vector<int> dist(n+1,1e9);
        
        dist[k]= 0,dist[0]=0;
        
        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            int u = node[1];
            int dis = node[0];
            
            for(auto i : adj[u])
            {
                int v = i[0], d = i[1];
                
                if(dist[v] > d+dis)
                {
                    dist[v] = d + dis;
                    
                    pq.push({dist[v],v});
                }
            }
        }
        
        res = *max_element(dist.begin(),dist.end());
        
        return res == 1e9 ? -1 : res;
        
    }
};