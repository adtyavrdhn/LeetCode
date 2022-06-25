class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int count = 0;
        
        if(nums.size()==1)
            return true;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])
            {
                if(count == 1)
                {
                    return false;
                }
                
                count++;
                if(i-2>=0)
                {
                    if(nums[i-2]>nums[i])
                    {
                        nums[i]=nums[i-1];
                    }
                }
              
            }
        }
        
        return count <= 1;
    }
};