class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        if(!nums.size())
            return 0;
        
         if(is_sorted(nums.begin(),nums.end()))
         {
             return 0;
         }
        
         vector<int>arr = nums;
        
         sort(arr.begin(),arr.end());
        
        
        int first_index = 0;
        int last_index = 0 ;
        
        for(int i=0;i<nums.size();i++)
        {
           if(nums[i]!=arr[i])
           {
               first_index = i;
               break;
           }
        }
        
        for(int i=nums.size()-1;i>=0;i--)
        {
           if(nums[i]!=arr[i])
           {
               last_index = i;
               break;
           }
        }
        
        return last_index - first_index + 1;
        
    }
};