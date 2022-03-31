class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int pre = 1;
        int suff = 1;
        
        int n = nums.size();
        vector<int> res(n,0);
        for(int i=0;i<n;i++)
        {
            res[i]=pre;
            pre=nums[i]*pre;
        }
        for(int i=n-1;i>=0;i--)
        {
            res[i] = res[i]*suff;
            suff = nums[i]*suff;
        }
        
        return res;
    }
};