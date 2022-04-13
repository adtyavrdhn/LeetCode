class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {      
        int n = nums.size();

        vector<int> next(n+1,0);
        vector<int> curr(n+1,0);
        
        
       for(int i=n-1;i>=0;i--)
       {
           for(int j=i-1;j>=-1;j--)
           {
               
             int pick = 0;
             if(j==-1 || nums[i]>nums[j])
             pick = 1 + next[i+1];
        
            
            int npick = next[j+1];
        
        
           curr[j+1] = max(pick,npick);
               
           }
           
           next = curr;
       }
        
        return curr[0];
    }
    
};