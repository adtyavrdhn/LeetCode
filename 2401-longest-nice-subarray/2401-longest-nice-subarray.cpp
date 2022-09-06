class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int num = 0,j=0;
        int res = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            while((num & nums[i])!=0)
            {
                num^= nums[j++];
            }
            num|= nums[i];
            res = max(res,i-j+1);
        }
        
        return res;
    }
};