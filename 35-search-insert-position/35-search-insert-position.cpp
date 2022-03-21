class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int high = n-1;
        int low = 0;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(nums[mid]==target)
                return mid;
            
            else if(target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        
        return low;
        
    }
};