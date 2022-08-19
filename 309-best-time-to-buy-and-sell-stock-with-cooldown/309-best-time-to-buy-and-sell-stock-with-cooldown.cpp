class Solution {
public:
    int maxProfit(vector<int>& arr) 
    {
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int> (2,-1));
        
        return f(arr,0,true,dp);
    }
    int f(vector<int>&arr, int index, bool flag,vector<vector<int>>&dp)
    {
        if(index>=arr.size())
        {
            return 0;
        }
        
        if(dp[index][flag]!=-1)
        {
            return dp[index][flag];
        }
        
        int res = 0;
        if(flag)
        {
            res = max(-arr[index]+f(arr,index+1,false,dp),f(arr,index+1,true,dp));
        }
        else
        {
            res = max(arr[index]+f(arr,index+2,true,dp),f(arr,index+1,false,dp));
        }
        
        return dp[index][flag] = res;
    }
};