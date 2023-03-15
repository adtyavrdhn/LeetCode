//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
    int f(string &s, int start, int n)
    {
        int i=0,j=s.size()-1;
        int count = 0;
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                if(i>=start && j<= (start+n-1)) // overlap with s2
                    return 1e9;
                 count++;
            }
               i++,j--;
        }
        
        return count;
    }
    int specialPalindrome(string s1, string s2){
       int m = s1.size();
       int n = s2.size();
       
       int res = 1e9;
       
        string temp = s1;
        
        for(int i=0;i<=m-n;i++)
        {
            int count = 0;
            for(int j=0;j<n;j++)
            {
                if(temp[i+j]!=s2[j])
                {
                    count++;
                }
                temp[i+j] = s2[j];
            }
            int costPall = f(temp,i,n);
            res = min(res,costPall + count);
            
            temp = s1;
        }
        
        return res == 1e9 ? -1 : res;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends