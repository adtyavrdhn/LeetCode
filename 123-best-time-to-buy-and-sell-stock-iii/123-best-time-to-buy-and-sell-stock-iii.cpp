class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
      
        vector<vector<int>> after(2,vector<int> (3,0));
        vector<vector<int>> curr(2,vector<int> (3,0));
     
        
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                int profit = 0;
                for(int k=1;k<=2;k++)
                {                 
                if(j)
                 profit = max(-prices[i]+after[0][k],after[1][k]);
        
                else
                profit = max(prices[i]+after[1][k-1],after[0][k]);
        
        
                 curr[j][k] = profit;
                }
            }
            
            after = curr;
        }
        
        
        return after[1][2];
        
    }
};