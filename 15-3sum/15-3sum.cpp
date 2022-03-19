class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        
        if(n<=2) return {};
        
        for(int i=0;i<n-2;i++)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
            int lo = i+1, hi = n-1, sum = -nums[i];
            
            while(lo < hi)
            {
                if(nums[lo]+nums[hi]==sum)
                {
                    res.push_back({nums[lo],nums[hi],nums[i]});
                    
                    while(lo < hi && nums[lo]==nums[lo+1])
                        lo++;
                    while(lo < hi && nums[hi]==nums[hi-1])
                        hi--;
                    
                    lo++;
                    hi--;
                }
                else if(nums[lo]+nums[hi]<sum)
                    lo++;
                else
                    hi--;
            }
            }
        }
        
        return res;
    }
};