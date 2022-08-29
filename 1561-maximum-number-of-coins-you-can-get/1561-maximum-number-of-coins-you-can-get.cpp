class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        int n = piles.size();
        sort(piles.begin(),piles.end());
        
        int me = n-2;
        int bob = 0;
        
        int res = 0;
        
        while(bob < me)
        {
            res+= piles[me];
            
            me-= 2;
            bob++;
        }
        
        return res;
    }
};