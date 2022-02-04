class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int sum = 0;
        int res = 0;
        
        for(int i=0;i<nums.size();++i)
        {
            sum += nums[i]==0?-1:1;
            
            if(sum==0)
                res = max(res,i+1);
            
            else if(mpp.find(sum)!=mpp.end())
                    res = max(res,i-mpp[sum]);
            
            else
                mpp[sum] = i;
        }
        
        return res;
    }
};