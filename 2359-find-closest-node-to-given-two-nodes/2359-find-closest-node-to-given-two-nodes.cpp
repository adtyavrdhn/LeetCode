class Solution {
public:
    void dfs(vector<int>& edges, int node, vector<int>& dist, int count)
    {
        if(dist[node]!=INT_MAX)
            return;
        
        dist[node]=count;
        
        int x = edges[node];
        
        if(x!=-1)
        {
             dfs(edges,x,dist,count+1);
        }
        
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        int n = edges.size();
        
        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);
        
        
        dfs(edges,node1,dist1,0);
        dfs(edges,node2,dist2,0);
        
        int res = 0;
        
        int maxmini = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            if(max(dist1[i],dist2[i]) < maxmini)
            {
                maxmini = max(dist1[i],dist2[i]);
                res = i;
            }
        }
        
        
//         for(auto i : dist1)
//             cout<<i<<" ";
        
//         cout<<endl;
        
//         for(auto i : dist2)
//             cout<<i<<" ";
        
//         cout<<endl;
        
        return maxmini == INT_MAX ? -1 : res;
        
    }
};