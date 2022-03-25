class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) 
    {
        helper(nums,0);
        return res;
    }
    
    void helper(vector<int>& nums, int index)
    {
        if(index==nums.size())
        {
            res.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            helper(nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
};