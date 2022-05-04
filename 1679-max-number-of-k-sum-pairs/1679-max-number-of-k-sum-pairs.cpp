class Solution {
public:
    int maxOperations(vector<int>& nums, int k) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int start = 0;
        int end = n- 1;
        
        int count = 0;
        while(start < end)
        {
            int sum = nums[start]+nums[end];
            
            if(sum > k)
            {
                end--;
            }
            else if(sum < k)
            {
                start++;
            }
            else
            {
                count++;
                start++;
                end--;
            }
                
        }
        
        return count;
    }
};