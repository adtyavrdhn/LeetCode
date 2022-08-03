class Solution
{
    public:
    
    bool f(vector<int>& nums)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                return false;
            }
        }
        
        return true;
    }
        int minimumOperations(vector<int> &nums)
        {
            bool flag = true;
            int count = 0;
            
            if(f(nums))
            {
                return 0;
            }
            
            while (flag)
            {
                count++;
                
                int mini = INT_MAX;
                for (int i = 0; i < nums.size(); i++)
                {
                    if (nums[i] != 0)
                        mini = min(nums[i], mini);
                }

                for (int i = 0; i < nums.size(); i++)
                {
                    if (nums[i] > 0)
                    {
                        nums[i] -= mini;
                    }
                }
                
                if(f(nums))
                {
                    flag = false;
                }
            }
            
            return count;
        }
};