class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        
        int n = intervals.size();
        int prev = 0;
        
        int count = 0;
        
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0] < intervals[prev][1])
            {
                if(intervals[prev][1] > intervals[i][1])
                {
                    prev = i;
                }
                count++;
            }
            else
                prev = i;
        }
        
        return count;
    }
};