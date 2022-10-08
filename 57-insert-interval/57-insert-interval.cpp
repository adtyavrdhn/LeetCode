class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& arr) 
    {
        int i=0, n = intervals.size();
        
        vector<vector<int>> res;
        
        while(i<n && intervals[i][1] < arr[0])
        {
            res.push_back(intervals[i++]);
        }
        
        while(i<n && intervals[i][0] <= arr[1])
        {
            arr[0] = min(arr[0],intervals[i][0]);
            arr[1] = max(arr[1],intervals[i][1]);
            
            i++;
        }
        res.push_back(arr);
        while(i<n)
        {
            res.push_back(intervals[i++]);
        }
        
        return res;
    }
};