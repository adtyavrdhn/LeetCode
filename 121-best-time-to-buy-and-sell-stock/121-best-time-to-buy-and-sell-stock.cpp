class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
      int minprice = prices[0];
      int maxprice = prices[0];
        
        int n = prices.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(prices[i]<minprice)
            {
                minprice=prices[i];
            }
                res=max(res,prices[i]-minprice);
            
              
        }
        
        return res;
    }
};