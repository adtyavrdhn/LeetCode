class Solution {
public:
    int dp[101];
    int numDecodings(string s) 
    {
        memset(dp,-1,sizeof(dp));
        return f(s,0);
    }
    int f(string s, int index)
    {
        if(s[index]=='0')
            return 0;
        
        if(index>=s.size()-1)
        {
            return 1;
        }
        
        if(dp[index]!=-1)
            return dp[index];
        
        int res = 0;
        
        res+= f(s,index+1);
        
        if(s[index]=='2'&&s[index+1]<='6' || s[index]=='1'&& s[index+1]<='9')
        {
            res+= f(s,index+2);
        }
        
        return dp[index] = res;
    }
};