class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int left = 0;
        int right = 25000000;
        
        for(int i=0;i<size(weights);i++)
            left = max(left,weights[i]);
        
        while(left < right)
        {
            int mid = (left+right)/2;
            int count = 1;
            int sum = 0;
            
            for(int i=0;i<size(weights);i++)
            {
                if(sum + weights[i] > mid)
                {
                    sum = 0;
                    count++;
                }
                sum+=weights[i];
            }

            if(count > days)
            {
                left = mid + 1;
            }
            else
                right = mid;
        }
        
        return left;
    }
};