class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) 
    {
        unordered_map<int,int> mppw;
        unordered_map<int,int> mppl;
        
        for(int i=0;i<m.size();i++)
        {
            mppw[m[i][0]]++;
            mppl[m[i][1]]++;
        }
        
        vector<vector<int>> res;
        vector<int> temp;
        
        for(auto i : mppw)
        {
            if(mppl.find(i.first)!=mppl.end()) continue;
            else
                temp.push_back(i.first);
        }
        
        vector<int> temp2;
        
        for(auto i : mppl)
        {
                if(mppl[i.first]==1)
                    temp2.push_back(i.first);  
        }
        
        sort(temp.begin(),temp.end());
        
        sort(temp2.begin(),temp2.end());
        
        res = {temp,temp2};
        
        return res;
    }
};