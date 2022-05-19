class Solution {
public:
    int splitArray(vector<int>& nums, int m) 
    {
        int low = 1;
        int high = 0;
        
        for(auto i : nums)
        {
            low = max(low,i);
            high += i;
        }
         int res =0;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            // cout<<mid<<endl;
            
            if(isfeasible(nums,m,mid))
            {
                high = mid-1;
                res = mid;
            }
            else low = mid + 1;
        }
        
        return res;
        
    }
    
    bool isfeasible(vector<int> &nums , int m, int splitSum)
    {
        int sum = 0;
        int count = 1;
        
        for(auto i : nums)
        {
            if(sum + i > splitSum)
            {
                count++;
                sum=0;
            }
            
            sum+= i;
        }
        
        return count<= m;
    }
};