class Solution {
public:
    unordered_map<string,bool> mpp;
    vector<int> dp;
    bool wordBreak(string s, vector<string>& dict) 
    {
        int n = s.size();
        dp.resize(n+1,-1);
        
        for(auto i : dict)
        {
            mpp[i]=true;
        }
        
        return f(s,0);
    }
    bool f(string s, int index)
    {
        if(index==s.size())
        {
            return true;
        }
        
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        
        for(int i=index;i<s.size();i++)
        {
            if(mpp[s.substr(index,i-index+1)] && f(s,i+1))
            {
                return dp[index] = true;
            }
        }
        
        return dp[index] = false;
    }
};