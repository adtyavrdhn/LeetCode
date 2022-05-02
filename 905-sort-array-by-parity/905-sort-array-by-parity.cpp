class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        vector<int> res;
        int n = nums.size();
        unordered_map<int,vector<int>> mpp;
        
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]%2].push_back(nums[i]);
        }
        
       
           
            for(auto x : mpp[0])
            {
                res.push_back(x);
            }
            for(auto x : mpp[1])
            {
                res.push_back(x);
            }
        
        
        
        
        
        return res;
    }
};