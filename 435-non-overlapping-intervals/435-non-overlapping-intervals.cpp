class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
       sort(intervals.begin(),intervals.end());
        
        int prev = intervals[0][1];
        int n = intervals.size();
        int res= 0;
        
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0] < prev)
            {
                prev = min(prev,intervals[i][1]);
                res++;
            }
            else
            {
                prev = intervals[i][1];
            }
        }
        
        return res;
    }
};