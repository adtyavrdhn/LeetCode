class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = size(nums);
        return f(nums,target,n-1,0);
    }
    
    int f(vector<int>& nums, int target, int index, int sum)
    {
        if(index==-1)
        {
            if(sum == target)
                return 1;
            else
                return 0;
        }
        
        int plus = f(nums,target,index-1,sum+nums[index]);
        int minus = f(nums,target,index-1,sum-nums[index]);
        
        return (plus+minus);
    }
};