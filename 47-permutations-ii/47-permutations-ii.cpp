class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        helper(nums,0);
        return res;
    }
    
     void helper(vector<int> nums, int index)
    {
        if(index==nums.size())
        {
            res.push_back(nums);
            // return;
        }
        else
         {
        for(int i=index;i<nums.size();i++)
        {
            if(i!=index && nums[i]==nums[index])
                continue;
            
            swap(nums[i],nums[index]);
            helper(nums,index+1);
          
        }
         }
    }
};