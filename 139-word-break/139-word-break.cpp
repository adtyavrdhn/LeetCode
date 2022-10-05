class Solution {
public:
    unordered_set<string> st;
    int dp[301];
    bool wordBreak(string s, vector<string>& dict) 
    {
        memset(dp,-1,sizeof(dp));
        for(auto i : dict)
            st.insert(i);
        
        return f(s,0);
    }
    bool f(string s, int index)
    {
        if(index>=s.size())
        {
            return true;
        }
        
        if(dp[index]!=-1)
            return dp[index];
        
        for(int i=index;i<s.size();i++)
        {
            string k = s.substr(index,i-index+1);
            
            if(st.find(k)!=st.end() && f(s,i+1))
            {
                return dp[index] = true;
            }
        }
        
        return dp[index] = false;
    }
};