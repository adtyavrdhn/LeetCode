class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        vector<vector<int>> arr;
        
        int n = startTime.size();
        
        vector<int> dp(n,-1);
        
        for(int i=0;i<startTime.size();i++)
        {
            arr.push_back({startTime[i],endTime[i],profit[i]});
        }
        
        sort(arr.begin(),arr.end());
        
        return f(arr,0,dp);
    }
    int f(vector<vector<int>>&arr, int index,vector<int>&dp)
    {
        if(index >= arr.size())
        {
            return 0;
        }
        
        if(dp[index]!=-1)
            return dp[index];
        
        int take=0,ntake=0;
        
        int newindex = find(arr,arr[index][1],index);
        
        take = arr[index][2] + f(arr,newindex,dp);
        
        ntake = f(arr,index+1,dp);
        
        
        return dp[index] = max(take,ntake);
    }
    int find(vector<vector<int>>&arr, int X, int i)
    {
        // need to find a start >= end of prev job
        
        // basically lower bound to speed up and reduce a state 
        
        int mid;
        
        int n = arr.size();
 
        int low = i+1;
        int high = n-1;
        
        int res = n;
    while (low <= high) 
    {
        mid = low + (high - low) / 2;
 
        if (X <= arr[mid][0]) 
        {
            high = mid-1;
            res = min(res,mid);
        }
 
        else 
        {
            low = mid + 1;
        }
    }
         return res;
    }
};