class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> pre(n,0);
        vector<int> suff(n,0);
        
        pre[0]=1;
        for(int i=1;i<n;i++)
        {
            pre[i]=nums[i-1]*pre[i-1];
        }
        suff[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=nums[i+1]*suff[i+1];
        }
        vector<int> res;
        
        for(int i=0;i<n;i++) res.push_back(pre[i]*suff[i]);
        
        return res;
    }
};