class Solution {
public:
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        helper(ds,k,n,0);
        return res;
        
    }
    void helper(vector<int>&ds, int k, int target, int start)
    {
        if(ds.size()==k && target==0)
            res.push_back(ds);
        
        
        for(int i=start;i<nums.size();i++)
        {
            if(nums[i]<=target)
            {
                ds.push_back(nums[i]);
                helper(ds,k,target-nums[i],i+1);
                ds.pop_back();
            }
        }
    }
};