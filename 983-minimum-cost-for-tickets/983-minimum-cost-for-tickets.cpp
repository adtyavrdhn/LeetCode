class Solution {
public:
    int res = INT_MAX;
    vector<int> dp;
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        dp.resize(1004,-1);
        f(days,costs,0);
        
        return res;
    }
    
    int f(vector<int>& days, vector<int>& costs, int index)
    {
    
        if(index >= days.size())
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];
        

        int one = costs[0] + f(days,costs,index+1);
        
        int nidx = lower_bound(begin(days), end(days), days[index]+7) - days.begin();
        int seven = costs[1] + f(days,costs,nidx);
        
        nidx = lower_bound(begin(days), end(days), days[index]+30) - days.begin();
        int thirty = costs[2] + f(days,costs,nidx);
        
        
        res = min({one,seven,thirty});
        
        return dp[index] = res;
    }
};