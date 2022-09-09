class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b)
    {
        if(a[0]==b[0])
        {
            return a[1] < b[1];
        }
        
        return a[0] > b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& arr) 
    {
        sort(arr.begin(),arr.end(),comp);
        
        int res =0;
        int max_def = INT_MIN;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i][1] < max_def)
            {
                res++;
            }
            else
            {
                max_def = arr[i][1];
            }
        }
        
        return res;
    }
};