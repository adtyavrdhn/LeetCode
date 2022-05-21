class Solution {
public:
    int res = INT_MAX;
    vector<int> dp;
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        dp.resize(1004,-1);
        f(days,costs,0,-1);
        
        return res;
    }
    
    int f(vector<int>& days, vector<int>& costs, int index, int bought_until)
    {
    
        if(index >= days.size())
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];
        
        if(days[index] <= bought_until)
        {
            return f(days,costs,index+1,bought_until);
        }
        
        int one = costs[0] + f(days,costs,index+1,days[index]);
        
        int nidx = lower_bound(begin(days), end(days), days[index]+7) - days.begin();
        int seven = costs[1] + f(days,costs,nidx,days[index]+6);
        
        nidx = lower_bound(begin(days), end(days), days[index]+30) - days.begin();
        int thirty = costs[2] + f(days,costs,nidx,days[index]+29);
        
        
        res = min({one,seven,thirty});
        
        return dp[index] = res;
    }
};