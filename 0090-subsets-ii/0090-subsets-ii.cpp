class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        vector<int> temp;
        
        f(nums,temp,0);
        
        return res;
    }
    void f(vector<int>&nums,vector<int>&temp,int index)
    {
        res.push_back(temp);
        
        for(int i=index;i<nums.size();i++)
        {
            if(i>index && nums[i]==nums[i-1])
                continue;
            
            temp.push_back(nums[i]);
            f(nums,temp,i+1);
            temp.pop_back();
        }
    }
};