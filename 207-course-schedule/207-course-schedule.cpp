class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        vector<int> indeg(n,0);
        
        vector<vector<int>> g(n,vector<int> (n,0));
        
        
        for(int i=0;i<pre.size();i++)
        {
            int x = pre[i][0];
            int y = pre[i][1];
            indeg[x]++;
            
            g[y][x]=1;
        }
        
        
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        
        
        int count = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            count++;
            for(int i=0;i<g.size();i++)
            {
                if(g[node][i]==1)
                {
                    indeg[i]--;
                    if(indeg[i]==0)
                        q.push(i);
                }
            }
            
        }
        
        return count == n;
    }
};