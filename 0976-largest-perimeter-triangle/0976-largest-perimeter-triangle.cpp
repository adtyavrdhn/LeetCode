class Solution {
public:
    int largestPerimeter(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        int res = 0;
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i-1]+nums[i-2] > nums[i])
            {
                res = max(res,nums[i-1]+nums[i-2]+nums[i]);
            }
        }
        
        return res;
    }
};