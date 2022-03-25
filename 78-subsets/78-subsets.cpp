class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> temp;
        helper(nums,temp,0);
        
        return res;
    }
    void helper(vector<int>& nums, vector<int>& temp,int index)
    {
        res.push_back(temp);
        
        for(int i=index;i<size(nums);i++)
        {
             temp.push_back(nums[i]);
             helper(nums,temp,i+1);
             temp.pop_back();
        }
        
        // helper(nums,temp,index+1);
    }
};