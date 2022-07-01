class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) 
    {
        
        vector<int> squeries = queries;
        
        sort(squeries.begin(),squeries.end());
        sort(intervals.begin(),intervals.end());
        
        // query -> size of interval
        unordered_map<int,int> mpp;
        
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        \
        int n = squeries.size();
        
        int index = 0;
        
        for(int i=0;i<n;i++)
        {
            int query = squeries[i];
            
            // only intervals that have a starting point on or before the query
            while(index < intervals.size() && intervals[index][0]<=query)
            {
                int left = intervals[index][0];
                int right = intervals[index][1]; 
                pq.push({right - left + 1, right});
                index++;
            }
            
            // if the end of the interval < query then it cannot contain query(removing intervals with ending point before the query)
            while (!pq.empty() && pq.top().second < query) 
            {
                pq.pop();
            }
            
            if (!pq.empty())
                mpp[query] = pq.top().first;
            else
                mpp[query] = -1;
        }
        
         vector<int> res;
         for(int i = 0; i < queries.size(); i++)
         {
               res.push_back(mpp[queries[i]]);
         }
        return res;
        
    }
};