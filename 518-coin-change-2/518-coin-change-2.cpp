class Solution {
public:
    int change(int target, vector<int>& nums) 
    {
        int n = nums.size();
        // vector<vector<int>> dp(n,vector<int> (target+1,0));
        vector<int> prev(target+1,0);
        prev[0]=1;
        
//         for(int i=0;i<n;i++)
//         {
//             dp[i][0]=1;
//         }
        
        for(int i=0;i<=target;i++)
        {
            if(i%nums[0]==0)
                prev[i]=1;
        }
        
        for(int i=1;i<n;i++)
        {
            vector<int> curr(target+1,0);
            
            for(int j=0;j<=target;j++)
            {
                int pick = 0;
                if(nums[i]<=j)
                    pick = curr[j-nums[i]];
                
                int npick = prev[j];
                
                curr[j] = (pick+npick);
            }
            prev = curr;
        }
        
        
        return prev[target];
    }
};