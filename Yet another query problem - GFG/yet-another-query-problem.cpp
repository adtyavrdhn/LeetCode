//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        
       vector<int> res;
       
       unordered_map<int,int> mpp;
       vector<int> freq(N,0);
       for(int i=N-1;i>=0;i--)
       {
           mpp[A[i]]++;
           freq[i] = mpp[A[i]];
       }
        
       for(auto q : Q)
       {
           int left = q[0];
           int right = q[1];
           int k = q[2];
           
           int count = 0;
           
           
           for(int i=left;i<=right;i++)
           {
               if(freq[i]==k)
               {
                    count++;
               }
           }
           
           res.push_back(count);
       }
       
       return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends