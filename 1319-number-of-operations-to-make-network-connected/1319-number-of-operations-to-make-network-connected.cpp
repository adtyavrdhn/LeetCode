class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x)
    {
        return parent[x]==x ? x : find(parent[x]);
    }
    void union_p(int i, int j)
    {
        int x = find(i);
        int y = find(j);
        
        if(x!=y)
        {
            if(rank[x]>rank[y])
            {
                parent[y]=x;
                rank[x]++;
            }
            else
            {
                parent[x]=y;
                rank[y]++;
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& arr) 
    {
        parent.resize(n);
        rank.resize(n,1);
        
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        int count = 0,extra = 0;
        
        for(int i=0;i<arr.size();i++)
        {
           int a = arr[i][0];
           int b = arr[i][1];
            
           int x = find(a);
           int y = find(b);
            
            if(x==y)
            {
                extra++;
            }
            else
            {
                union_p(a,b);
            }
            
        }
        
        for(int i=0;i<parent.size();i++)
            if(parent[i]==i) count++;
        
         if (extra >= count-1) return count-1;
        
        return -1;
    }
};