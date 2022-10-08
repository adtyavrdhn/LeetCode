class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) 
    {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        
        int prev = arr[0][1];
        
        int res = 0;
        
        for(int i=1;i<n;i++)
        {
            if(arr[i][0] < prev) // overlap
            {
                prev = min(prev,arr[i][1]);
                res++;
            }
            else
                prev = arr[i][1];
        }
        
        return res;
    }
};