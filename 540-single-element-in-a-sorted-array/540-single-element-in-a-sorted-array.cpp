class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        
        int res {};
        
        for(int i=0;i<nums.size();i++)
        {
          res = res^nums[i];  
        }
        
        return res;
    }
};