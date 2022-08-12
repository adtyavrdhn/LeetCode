class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        
        int res = nums[0];
        
        int sum  = 0;
        
        for(int i=0;i<n;i++)
        {
            sum = max(nums[i],sum+nums[i]);
            
            res = max(res,sum);
        }
        
        return res;
    }
};