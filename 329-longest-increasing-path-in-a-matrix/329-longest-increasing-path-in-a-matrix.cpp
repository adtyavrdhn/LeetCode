class Solution {
public:
    vector<vector<int>> dp;
    int longestIncreasingPath(vector<vector<int>>& arr) 
    {
        int m = arr.size();
        int n = arr[0].size();
        dp.resize(m+1, vector<int> (n+1,-1));
        
        int res = INT_MIN;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                res = max(res, f(arr,i,j,-1));
            }
        }
        
        return res;
    }
    int f(vector<vector<int>>&arr, int i, int j, int last)
    {
        if(i<0 || j<0 || i>=arr.size() || j>=arr[i].size() || arr[i][j]<=last)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int a = f(arr,i-1,j,arr[i][j]);
        int b = f(arr,i,j-1,arr[i][j]);
        int c = f(arr,i+1,j,arr[i][j]);
        int d = f(arr,i,j+1,arr[i][j]);
        
        return dp[i][j] = 1 + max({a,b,c,d});
    }
};