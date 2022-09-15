class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        map<string,multiset<string>> mpp;
        
        int n = tickets.size()+1;
        
        for(auto i : tickets)
        {
            string x = i[0];
            string y = i[1];
            
            mpp[x].insert(y);
        }
        
        vector<string> res;
        
        f("JFK",mpp,res);
        
        reverse(res.begin(),res.end());
        
        return res;
    }
    void f(string airport,map<string,multiset<string>>& mpp,vector<string>&res)
    {
        while (!mpp[airport].empty()) 
        {
            string next = *mpp[airport].begin();
            
            mpp[airport].erase(mpp[airport].begin());
            
            f(next, mpp,res);
        }
        
        res.push_back(airport);
    }
};