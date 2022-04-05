class Solution {
public:
    int change(int target, vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (target+1,0));
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=0;i<=target;i++)
        {
            if(i%nums[0]==0)
                dp[0][i]=1;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                int pick = 0;
                if(nums[i]<=j)
                    pick = dp[i][j-nums[i]];
                
                int npick = dp[i-1][j];
                
                dp[i][j] = (pick+npick);
            }
        }
        
        
        return dp[n-1][target];
    }
//     int f(vector<int>&nums , int index, int target,vector<vector<int>> &dp)
//     {
//         if(target==0) return 1;
        
        
//         if(index==0)
//         {
//             if(target%nums[index]==0)
//                 return 1;
//             else
//                 return 0;
//         }
        
//         if(dp[index][target]!=-1) return dp[index][target];
         
//         int pick = 0;
//         if(nums[index]<=target)
//          pick = f(nums,index,target-nums[index],dp);
        
//         int npick = f(nums,index-1,target,dp);
        
//         return dp[index][target] = (pick+npick);
//     }
};