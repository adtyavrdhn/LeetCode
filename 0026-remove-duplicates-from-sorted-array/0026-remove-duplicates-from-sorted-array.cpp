class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        int index = 1;
        
        for(int i=1;i<n;i++)
        {
          if(nums[i]!=nums[i-1])
              nums[index++]=nums[i];
        }
        
        return index;
    }
};