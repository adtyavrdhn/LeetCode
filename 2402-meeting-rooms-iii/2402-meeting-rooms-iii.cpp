class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        vector<int> res(n,0);
        
        vector<long long> times(n,0);
        
        sort(meetings.begin(),meetings.end());
        
        for(int i=0;i<meetings.size();i++)
        {
            int start = meetings[i][0];
            int end = meetings[i][1];
            
            bool flag = false;
            
            int minindex = 1;
            int mintime = INT_MAX;
            
            for(int j=0;j<n;j++)
            {
                if(times[j] < mintime)
                {
                    // if we have to wait for a room to be empty, then will choose the one which will be vacated first
                    mintime = times[j],minindex = j;
                }
                
                if(times[j] <= start)
                {
                   // if a room is currently empty to use   
                    flag = true;
                    res[j]++;
                    times[j] = end; // we have a new ending time for our room as there is a new meeting
                    break; // if we have an empty room, we will use it and we dont need to check any further
                }
            }
            
            if(!flag)
            {
                res[minindex]++;
                times[minindex] += (1ll)*(end-start); // previous ending time + duration of new meeting will be the new ending time
            }
        }
        
        int room = 0;
        for(int i=0;i<n;i++)
        {
            if(res[room] < res[i])
            {
                room = i;
            }
        }
        
        return room;
    }
};