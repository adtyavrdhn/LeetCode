class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        int prev = 0;
        
        int n = intervals.size();
        
        sort(intervals.begin(),intervals.end());
        
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
            {
                prev = i;
            }
        }
        
        return count;
    }
};