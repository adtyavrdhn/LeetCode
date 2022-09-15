class Solution {
public:
    #define inf 1e9
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<int> dist(n+1,inf);
        dist[k] = 0;
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<times.size();j++)
            {
                int u = times[j][0];
                int v = times[j][1];
                int wt = times[j][2];
                
                dist[v] = min(dist[v],dist[u]+wt);
            }
        }
        
        int res = 0;
        for(int i=1;i<=n;i++)
        {
            // cout<<dist[i]<<" ";
            res = max(res,dist[i]);
        }
        
        return res == 1e9 ? -1 : res;
    }
};