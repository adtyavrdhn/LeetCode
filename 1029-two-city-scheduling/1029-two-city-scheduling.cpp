class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        vector<int> diff;
        int res=0;
        
        for(int i=0;i<size(costs);i++)
        {
            res+=costs[i][0];
            diff.push_back(costs[i][1]-costs[i][0]);
        }
        
        sort(diff.begin(),diff.end());
        
        for(int i=0;i<size(diff)/2;i++)
        {
            res+=diff[i];
        }
        
        return res;
    }
};