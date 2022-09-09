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
        
        int res = 0;
        int max_def = INT_MIN;
        int max_att = INT_MIN;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i][1] < max_def && arr[i][0]<max_att)
            {
                res++;
            }
            max_def = max(max_def,arr[i][1]);
            max_att = max(max_att,arr[i][0]);
        }
        
        return res;
    }
};