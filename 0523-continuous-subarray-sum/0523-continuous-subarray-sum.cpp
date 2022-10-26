class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        
        unordered_map<int,int> mpp;
        
        mpp.insert({0,-1});
        
        int sum = 0;
        
        for(int i=0;i<n;i++)
        {
            sum+= nums[i];
            sum%=k;
            
            if(mpp.find(sum)==mpp.end())
            {
               mpp[sum]=i;
            }
            else if(i-mpp[sum]>1)
                return true;
                
        }
        
        return false;
    }
};