class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int find(int x)
    {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }
    void unionop(int i, int j)
    {
        int x = find(i);
        int y = find(j);
        
        
        if(x!=y)
        {
            if(size[x] >= size[y])
            {
                parent[y] = x;
                size[x]++;
            }
            else
            {
                parent[x] = y;
                size[y]++;
            }
        }
    }
    bool f(string s, string t)
    {
        if(s==t)
            return true;
        
//         string temp = s;
//         vector<int> index;
        
//         for(int i=0;i<s.size();i++)
//         {
//             if(s[i]!=t[i])
//                 index.push_back(i);
//         }
        
//         if(index.size() > 2)
//             return false;
        
//         swap(temp[index[0]],temp[index[1]]);
        
//         return temp == t;
        int count = 0;
        for(int i=0;i<s.size();i++)
            if(s[i]!=t[i]) count++;
        
        return count <= 2;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        
        parent.resize(n,0);
        size.resize(n,1);
        
        for(int i=1;i<n;i++)
            parent[i] = i;
        
        
        for(int i=0;i<strs.size();i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(f(strs[i],strs[j]))
                    unionop(i,j);
            }
        }
        
        int res = 0;
        
        for(int i=0;i<n;i++)
            res += parent[i]==i;
        
        return res;
            
    }
};