class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) 
    {
        vector<int> starts;
        vector<int> ends;
        
        for(int i=0;i<flowers.size();i++)
        {
            starts.push_back(flowers[i][0]);
            ends.push_back(flowers[i][1]);
        }
        
        sort(starts.begin(),starts.end());
        
        sort(ends.begin(),ends.end());
        
        vector<int> res;
        
        for(int i=0;i<persons.size();i++)
        {
            int time = persons[i];
            
            int ub = upper_bound(starts.begin(),starts.end(),time)-starts.begin();
            int lb = lower_bound(ends.begin(),ends.end(),time)-ends.begin();
            
            res.push_back(ub-lb);
        }
        
        return res;
    }
};