class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries)
    {
        int n = s.size();
        
        vector<int> left(n,-1);
        vector<int> right(n,n);
        
        vector<int> res;
        
        
        left[0] = -1;
        
        for(int i=1;i<n;i++)
        {
            if(s[i]=='|')
                left[i]=i;
            
            else left[i] = left[i-1];
        }
        
        right[n-1]=n;
        
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='|')
                right[i]=i;
            
            else
                right[i]=right[i+1];
        }
        
        vector<int> pre(n,0);
        
        pre[0] = s[0]=='*';
        
        for(int i=1;i<n;i++)
        {
            pre[i] += pre[i-1] + (s[i]=='*');
        }
        
        for(auto q : queries)
        {
            int l = q[0];
            int r = q[1];
            
            int start = right[l];
            int end = left[r];
            
            if(end <= start)
            {
                 res.push_back(0);
            }
            else
            {
                 res.push_back(pre[end]-pre[start]);
            }
               
        }
        
        return res;
    }
};