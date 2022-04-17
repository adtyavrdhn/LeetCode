class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        unordered_map<int,int> mpp;
        
        for(int i=0;i<tasks.size();i++) mpp[tasks[i]]++;
        
        int res = 0;
        
        for(auto i : mpp)
        {
            if(i.second == 1) return -1;
            
            res+=(i.second)/3;
            
             if(i.second%3==1 || i.second%3==2)
                     res++;
        }
        
        return res;
    }
};