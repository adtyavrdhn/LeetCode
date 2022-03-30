class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = size(nums);
        vector<int> dp(n,0);
        
        int prev=nums[0];
        int prev2=0;
        int curr=0;
        for(int i=1;i<n;i++)
        {    
           int take = nums[i];
            if(i>1) take+=prev2;
            
            int dont = prev;
            
            curr = max(take,dont);
            
             prev2 = prev;
           prev = curr;
        }
        
        return prev;
    }
};