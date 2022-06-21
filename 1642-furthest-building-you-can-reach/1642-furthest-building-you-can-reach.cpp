class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) 
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int n = h.size();
        int bsum = 0;
        
        
        for(int i=1;i<n;i++)
        {
            int diff = h[i]-h[i-1];
            
            if(diff <= 0)
                continue;
            
            pq.push(diff);
            
            
            if(pq.size()>ladders)
            {
                bsum+= pq.top();
                pq.pop();
            }
            
            if(bsum > bricks) return i-1;
            
        }
        
        return h.size()-1;
    }
};