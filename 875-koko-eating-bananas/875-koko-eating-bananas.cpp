class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = 1e9;
        
        
        
        while(start < end)
        {
            int mid = (start + end)/2;
            
            int sum = 0;
            for(int i=0;i<piles.size();i++)
            {
                sum+= piles[i]/mid + (piles[i]%mid != 0);
            }
            
            if(sum <= h)
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        
        
        return end;
    }
};