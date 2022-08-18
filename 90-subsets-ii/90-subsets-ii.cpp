class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        vector<int> temp;
        f(nums,0,temp);
        
        return res;
    }
    void f(vector<int>&nums,int index,vector<int>&temp)
    {
        res.push_back(temp);
        
        for(int i=index;i<nums.size();i++)
        {   
            if(i>index && nums[i]==nums[i-1]) continue;
            
            temp.push_back(nums[i]);
            f(nums,i+1,temp);
            temp.pop_back();
        }
    }
};