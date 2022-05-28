class Solution {
public:
    long long res;
    vector<long long> dp;
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) 
    {
        int sz = rides.size();
        dp.resize(sz+1,-1);
        sort(rides.begin(),rides.end());
        return f(n,rides,0);
    }
    
    long long f(int n, vector<vector<int>>& rides, int index)
    {
        if(index>=rides.size())
        {
            return 0;
        }
        if(dp[index]!=-1)
            return dp[index];
        
            auto j = lower_bound(rides.begin() + index
                             , rides.end()
                             , rides[index][1]
                             , [](vector<int>&vec, int temp){
            return vec[0] < temp;
        }) - rides.begin();
          long long  pick = rides[index][1]-rides[index][0] + rides[index][2] + f(n,rides,j);
        
        
        long long npick = f(n,rides,index+1);
        
        return dp[index] = max(pick,npick);
        
    }
};