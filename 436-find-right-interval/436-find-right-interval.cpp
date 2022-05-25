class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        unordered_map<int,int> mpp;
        
        vector<int> arr;
        vector<int> res;
        
        for(int i=0;i<n;i++)
        {
            mpp[intervals[i][0]]=i;
            arr.push_back(intervals[i][0]);
        }
        
        sort(arr.begin(),arr.end());
        
        
        for(int i=0;i<intervals.size();i++)
        {
            int indx = lower_bound(arr.begin(),arr.end(),intervals[i][1]) - arr.begin();
            
            if(indx==arr.size())
            {
                res.push_back(-1);
            }
            else
            {
                int num = arr[indx];
                int interval_index = mpp[num];
                res.push_back(interval_index);
            }
        }
        
        return res;
    }
};