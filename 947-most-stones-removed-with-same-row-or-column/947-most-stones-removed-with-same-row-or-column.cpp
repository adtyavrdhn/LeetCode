class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x)
    {
        return parent[x]== x ? x : find(parent[x]);
    }
    void union_op(int i,int j)
    {
        int x = find(i);
        int y = find(j);
        
            if(rank[x]<rank[y])
            {
                 parent[x]=y;
                 rank[y]++;
                  
            }
            else
            {
                  parent[y]=x;
                  rank[x]++;
            }
                     
    }                
    int removeStones(vector<vector<int>>& stones) 
    {
        int n = stones.size();
        parent.resize(n);
        
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        rank.resize(n,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                    union_op(i,j);
                
            }
        }
        
        int c = 0;
        
        for(int i=0;i<n;i++)
        if(parent[i]==i) c++;
    
        return n-c;
       
    }
};