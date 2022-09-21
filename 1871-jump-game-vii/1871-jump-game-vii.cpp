class Solution
{
    public:
        bool canReach(string s, int mini, int maxi)
        {
            queue<int> q;
            int n = s.size();
            
            if(s[n-1]=='1')
                return false;
            
            q.push(0);
            
            int start = 0;
            
            while(!q.empty())
            {
                auto x = q.front();
                q.pop();
                
                if(x==n-1 && s[x]=='0')
                {
                    return true;
                }
                
                 start = max(start,x+mini);
                 int end = min(n-1,x+maxi);
                
                for(int j = start;j<=end;j++)
                {
                    if(s[j]=='0')
                        q.push(j);
                }
                
                start = end + 1;
            }
            
            return false;
        }
};