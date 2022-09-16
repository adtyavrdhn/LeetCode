class Solution {
public:
    int dp[2005][2005];
    bool canCross(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        
        return f(nums,0,1); // 0 index 1 jump is the initial condition
    }
    // the index we were at and the jump we took from there are the two states
    bool f(vector<int>&nums, int index, int jump)
    {
        int curr = nums[index] + jump; // if we jump from prev index taking the jump 'jump'
        int n = nums.size();
        
        if(curr == nums[n-1]) //jump onto the last stone
        {
            return true;
        }
        
        if(curr > nums[n-1] || jump<=0) // jump past the last stone
        {
            return false;
        }
        
        if(dp[index][jump]!=-1)
            return dp[index][jump];
        
        // we also need to make sure that this new position that we have landed on has a stone on it, we will use binary search for that
        int newpos = lower_bound(nums.begin(),nums.end(),curr)-nums.begin();
        
        if(newpos == n || nums[newpos]!=curr)
        {
            return false;
        }
        
        bool res = false;
        
        res = f(nums,newpos,jump) | f(nums,newpos,jump+1) | f(nums,newpos,jump-1);
        
        return dp[index][jump] = res;
        
    }
};