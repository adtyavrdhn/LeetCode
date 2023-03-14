//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int dp[401][401];
    int f(int i, int j,vector<int>&nums)
    {
        if(i>j)
        {
            return 0;
        }
        
        int res = 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        for(int k=i;k<=j;k++)
        {
            int left  = nums[i-1];
            int right = nums[j+1];
            
            int coins = (left*nums[k]*right) + f(i,k-1,nums) + f(k+1,j,nums);
            
            res = max(res,coins);
        }
        
        return dp[i][j] = res;
    }
        int maxCoins(int n, vector <int> &nums)
        {
          memset(dp,-1,sizeof(dp));
        
          nums.push_back(1);
        
          nums.insert(nums.begin(),1);
       
          return f(1,n,nums);
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends