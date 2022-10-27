//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dp[101][101];
    int removals(vector<int>& arr, int k){
        sort(arr.begin(),arr.end());
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        return f(arr,k,0,n-1);
    }
    int f(vector<int>&arr, int k,int i, int j)
    {
        if(i>j)
        {
            return 1e9;
        }
        
        if(arr[j]-arr[i]<=k)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int front = 1 + f(arr,k,i+1,j);
        int back = 1 + f(arr,k,i,j-1);
        
        return dp[i][j] = min(front,back);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.removals(a,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends