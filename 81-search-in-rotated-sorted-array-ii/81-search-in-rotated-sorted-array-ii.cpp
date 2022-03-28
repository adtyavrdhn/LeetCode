class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        
        while(low <= high)
        {
            while(low < high && nums[low]==nums[low+1])
                low++;
            
             while(low < high && nums[high]==nums[high-1])
                high--;
            
            int mid = (low+high)/2;
            
            if(nums[mid]==target) return true;
            else if(nums[low]<=nums[mid]) // left half sorted
            {
                if(nums[low]<=target && nums[mid]>=target)
                {
                    high = mid -1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if(nums[mid]<=target && nums[high]>=target)
                {
                    low = mid + 1;
                  
                }
                else
                {
                    high = mid -1;
                }
            }
        }
        
        return false;
    }
};