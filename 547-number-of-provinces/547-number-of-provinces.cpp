class Solution {
public:
     vector<int> parent;
    int find(int x)
    {
        return parent[x]==x ? x : find(parent[x]);
    }
    
     void union_p(int i, int j) 
    {
        i = find(i);
        j = find(j);
        
        if(i!=j)
            parent[j] = i;
    }
    
    int findCircleNum(vector<vector<int>>& arr) 
    {
          int n = arr.size();
          parent.resize(n);
        
            for (int i = 0; i < n; i++)
 			   parent[i] = i;
        
        int res = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i][j]==1)
                {
                  union_p(i,j);
                }
                
            }
        }
        
        for(int i=0;i<parent.size();i++)
        {
            if(parent[i]==i)
                res++;
        }
        
        return res;
    }
};