class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> pref(n,1);
        vector<int> suff(n,1);
        
        pref[0] = 1;
        suff[0] = 1;
        vector<int> res;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]<=nums[i-1])
            {
                pref[i] = pref[i-1]+1;
            }
        }
        
         for(int i=1;i<n;i++)
        {
            if(nums[i]>=nums[i-1])
            {
                suff[i] = suff[i-1]+1;
            }
        }
        
        for(int i=k;i<n-k;i++)
        {
            if(pref[i-1]>=k && suff[i+k]>=k)
            {
                res.push_back(i);
            }
        }
        
        return res;
    }
};