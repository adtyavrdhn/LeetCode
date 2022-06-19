class Solution {
public:
    int res = INT_MAX;
    vector<vector<int>> dp;
    int minimumNumbers(int num, int k) 
    {
          if(num == 0 && k == 0) return 0;
        
        
        if(k == 0) 
        return num%10 == k ? 1 : -1;

        
       dp.resize(num+1, vector<int>(num+1, -1));
        
        
        
//         for(auto i : nums)
//             cout<<i<<" ";
        
         res = f(k,num,0);
        
        return res == INT_MAX ? -1 : res;
        
    }
    
    int f(int num, int target, int count)
    {
         if(target==0)
        {
           return count;
        }
        
        if(num > target)
        {
            return INT_MAX;
        }
        
        if(dp[num][target]!=-1)
        {
            return dp[num][target];
        }
        
        int pick = INT_MAX, npick;
        
        if(num <= target)
        {
            pick =  f(num,target-num,count+1);
        }
        
        npick =  f(num+10,target,count);
        
        return dp[num][target] = min(pick,npick);
        
    }
};