class Solution {
public:
    int rob(vector<int>& arr) 
    {
    int n = arr.size();
        if(n==1) return arr[0];
    vector<int> arr1;
    vector<int> arr2;
    
    for(int i=0; i<n; i++)
    {
        
        if(i!=0) arr1.push_back(arr[i]);
        if(i!=n-1) arr2.push_back(arr[i]);
    }
    
     int ans1 = solve(arr1);
     int ans2 = solve(arr2);
    
    return max(ans1,ans2);
       
    }
    
    int solve(vector<int>& arr)
    {
     int n = arr.size();
     int prev = arr[0];
     int prev2 =0;
    
    for(int i=1; i<n; i++)
    {
         int pick = arr[i];
        if(i>1) pick += prev2;
        
        int nonPick = 0 + prev;
        
        int cur = max(pick, nonPick);
        prev2 = prev;
        prev= cur;
        
    }
        
    return prev;
        
    }
};