class Solution {
public:
    long long res;
    vector<long long> dp;
    vector<int> starts;
    unordered_map<int,int> mpp;
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) 
    {
        int sz = rides.size();
        dp.resize(sz+1,-1);
        starts.resize(sz,0);
        sort(rides.begin(),rides.end());     
        
        for(int i=0;i<rides.size();i++)
        {
            starts[i] = rides[i][0];
        }
        
        return f(rides,0);
    }
    
    long long f(vector<vector<int>>& rides, int index)
    {
        if(index>=rides.size())
        {
            return 0;
        }
        if(dp[index]!=-1)
            return dp[index];        
        
        long long nstart = lower_bound(starts.begin(),starts.end(),rides[index][1]) - starts.begin();
        
        long long  pick = rides[index][1]-rides[index][0] + rides[index][2] + f(rides,nstart);
        
        
        long long npick = f(rides,index+1);
        
        return dp[index] = max(pick,npick);
        
    }
};