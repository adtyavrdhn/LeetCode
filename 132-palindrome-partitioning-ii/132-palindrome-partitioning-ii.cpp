class Solution {
public:
    int dp[3001];
    int minCut(string s) 
    {
        memset(dp,-1,sizeof(dp));
        return f(s,0)-1;
    }
    
    int f(string &s, int index)
    {
        if (index >= s.size())
        {
            return 0;
        }
        
        if(dp[index]!=-1)
            return dp[index];
        
        int res = INT_MAX;

        for (int i = index; i < s.size(); i++)
        {
            if (ispall(s,index,i))
            {
                res = min(res,1+f(s, i + 1));
            }
        }
        
        return dp[index] = res;
    
    }
   bool ispall(string &s, int low, int high) 
   {
        while (low < high) 
        {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
};