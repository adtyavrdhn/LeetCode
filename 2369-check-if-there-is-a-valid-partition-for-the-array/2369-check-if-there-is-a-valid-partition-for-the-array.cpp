class Solution {
public:
    vector<int> dp;
    bool validPartition(vector<int>& nums) 
    {
        dp.resize(nums.size()+1,-1);
        return f(nums, 0);
    }
    bool f(vector<int>&nums, int index)
    {
        if(index==nums.size())
        {
            return true;
        }
        
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        
        if(index+1 < nums.size() && nums[index]==nums[index+1])
        {
            // case 1
            if(f(nums,index+2))
            {
                return dp[index] = true;
            }
            
            // case 2
            if(index+2<nums.size() && nums[index]==nums[index+2])
            {
                if(f(nums,index+3))
                {
                    return dp[index] = true;
                }
            }
        }
        
        // case 3
        if(index+2<nums.size() && nums[index+1] == nums[index] + 1 && nums[index+2] == nums[index]+2)
        {
            if(f(nums,index+3))
            {
                return dp[index] = true;
            }
        }
        
        return dp[index] =  false;
    }
};