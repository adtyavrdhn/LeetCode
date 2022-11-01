class Solution {
public:
    int mySqrt(int x) 
    {
        
        int low = 0, high = INT_MAX - 1;
        long long int res = 0;
        
        while(low<=high)
        {
            long long int mid = (low + (high-low)/2);
            
            if(mid*mid<=x)
            {
                res = max(res,mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        
        return res;
    }
};