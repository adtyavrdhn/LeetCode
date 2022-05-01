class Solution {
public:
    int minimumCardPickup(vector<int>& cards) 
    {
        unordered_map<int,int> mpp;
        int n = cards.size();
        int res = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(mpp.find(cards[i])!=mpp.end())
            {
                res = min(res, i-mpp[cards[i]]+1);
            }
            
            mpp[cards[i]]=i;
        }
        
        
        return res==INT_MAX ? -1 : res;
    }
};