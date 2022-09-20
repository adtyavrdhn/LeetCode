class Solution {
public:
    int dp[1001];
    int maxJumps(vector<int>& arr, int d) 
    {
        memset(dp,-1,sizeof(dp));
        int res = 0;
        int n = arr.size();
        
        for(int i=0;i<n;i++)
        {
            res = max(res, f(arr,d,i));
        }
        
        return res+1;
    }
    
    int f(vector<int>&arr, int d, int index)
    {
        int res = 0;
        int n = arr.size();
        
        if(dp[index]!=-1)
            return dp[index];
        
        for(int i=index-1;i>= max(index-d,0) && arr[i]<arr[index];i--)
        {
            res = max(res, 1 + f(arr,d,i));
        }
        
        for(int i=index+1;i<= min(index+d,n-1) && arr[i]<arr[index];i++)
        {
            res = max(res, 1 + f(arr,d,i));
        }
        
        return dp[index] = res;
        
    }
};