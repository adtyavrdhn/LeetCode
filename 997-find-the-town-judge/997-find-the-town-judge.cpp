class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        unordered_map<int,pair<int,int>> mpp;
        
        for(int i=0;i<trust.size();i++)
        {
              mpp[trust[i][0]].first++;
              mpp[trust[i][1]].second++;
        }
          
        
        for(int i=1;i<=n;i++)
        {
            if(mpp[i].first==0 && mpp[i].second==n-1) return i;
        }

        
        
        return -1;
    }
};