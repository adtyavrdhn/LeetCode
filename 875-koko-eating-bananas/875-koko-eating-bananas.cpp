class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int left = 1;
        int right = (int)1e9;
        
        while(left<right)
        {
            int mid = (left+right)/2;
            int sum=0;
            for(int i=0;i<size(piles);i++)
            {
                sum+=(piles[i]+mid-1)/mid;
            }
            
            if(sum>h)
            {
                left = mid + 1;
            }
            else
                right = mid;
        }
        
        return left;
    }
};