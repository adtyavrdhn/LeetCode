class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        int n = piles.size();
        
        sort(piles.begin(),piles.end());
        
        for(auto i : piles)
        {
            cout<<i<<" ";
        }
        
        int me = n-2;
        int alice = n-1;
        int bob = 0;
        
        
        int res = 0;
        
        while(bob < me)
        {
            res+= piles[me];
            alice -= 2;
            me-= 2;
            bob++;
        }
        
        // cout<<endl;
        
        return res;
    }
};