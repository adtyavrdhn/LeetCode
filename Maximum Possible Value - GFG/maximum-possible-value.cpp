//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
       
       long long res = 0;
       // lets make squares
       
       int count = 0;
       
       int minmStick = INT_MAX;
       
       for(int i=0;i<N;i++)
       {
           if(B[i]/2)
           {
               res+= A[i] * (B[i] / 2) * 2;
               count+= B[i]/2;
               minmStick = min(minmStick,A[i]);
           }
       }
       
       if(count % 2 != 0)
       {
           res -= minmStick*2;
       }
       
       return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends