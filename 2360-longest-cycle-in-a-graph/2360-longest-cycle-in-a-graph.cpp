class Solution
{
    public:
        int res = 0;
    void f(vector<int> &edges, vector<bool> &vis, int node, int len,unordered_map<int,int>&mpp)
    {
        
        if (vis[node])
        {
            if (mpp.find(node) != mpp.end())
            {
                res = max(res, len - mpp[node]);
            }
            return;
        }
        
        vis[node]=true;
        
        mpp[node]=len;
        
        int x = edges[node];
        
        if(x!=-1)
        f(edges,vis,x,len+1,mpp);
        
    }
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<bool> vis(n, false);
        
        res = -1;

        for (int i = 0; i< n; i++)
        {
            if (!vis[i])
            {
                unordered_map<int, int> mpp;
                f(edges, vis, i, 0,mpp);
            }
        }
        
        return res;
    }
};