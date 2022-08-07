class Solution {
public:
    int f(vector<int>&nums, int k)
    {
        int i=0,j=0;
        
        int n = nums.size();
        
        unordered_map<int,int> mpp;
        
        int count = 0;
        
        while(j<n)
        {
            mpp[nums[j]]++;
            
            while(i<=j && mpp.size()>k)
            {
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0)
                {
                    mpp.erase(nums[i]);
                }
                i++;
            }
            
            count+= j - i + 1;
            
            j++;
        }
        
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return f(nums,k)-f(nums,k-1);
    }
};