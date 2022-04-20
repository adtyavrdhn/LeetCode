class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x)
    {
        return parent[x]==x ? x : find(parent[x]);
    }
    void union_op(int i, int j)
    {
        int x = find(i);
        int y = find(j);
        
        if(x != y)
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
    bool equationsPossible(vector<string>& arr) 
    {
        int n = arr.size();
        parent.resize(26);
        rank.resize(26,1);
        
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        
        for(int i=0;i<n;i++)
        {
            int a = arr[i][0]-'a';
            int b = arr[i][3]-'a';
            
               if(arr[i][1]=='=')
               union_op(a,b);
            
        }
        for(int i=0;i<n;i++)
        {
            int a = arr[i][0]-'a';
            int b = arr[i][3]-'a';
            
             if(arr[i][1]=='!')
            {
             int x = find(a);
             int y = find(b);
                if(x==y)
                    return false;
            }
        }
        
        
        return true;
    }
};