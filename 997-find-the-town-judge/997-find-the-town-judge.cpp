class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        unordered_map<int,int> mppo;
        unordered_map<int,int> mppi;
        
        for(int i=0;i<trust.size();i++)
        {
              mppo[trust[i][0]]++;
              mppi[trust[i][1]]++;
        }
          
        
        for(int i=1;i<=n;i++)
        {
            if(mppo.find(i)==mppo.end() && mppi[i]==n-1) return i;
        }

        
        
        return -1;
    }
};