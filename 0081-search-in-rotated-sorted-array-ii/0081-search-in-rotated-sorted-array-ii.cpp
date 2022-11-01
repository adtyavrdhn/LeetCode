class Solution
{
    public:
        bool search(vector<int> &nums, int target)
        {
            int n = nums.size();

            int low = 0, high = n - 1;

            while (low <= high)
            {
                
                while(low<high && nums[low]==nums[low+1])
                    low++;
                
                while(low<high && nums[high]==nums[high-1])
                    high--;
                
                
                int mid = low + (high - low) / 2;	// l+r > INT_MAX -> overflow

                if (nums[mid] == target)
                    return true;

                if (nums[low] <= nums[mid])	// left half is sorted
                {
                    if (nums[low] <= target && target < nums[mid])
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                else
                {
                    if (target >= nums[mid] && target <= nums[high])
                    {
                        low = mid + 1;
                    }
                    else
                        high = mid - 1;
                }
            }

            return false;
        }
};