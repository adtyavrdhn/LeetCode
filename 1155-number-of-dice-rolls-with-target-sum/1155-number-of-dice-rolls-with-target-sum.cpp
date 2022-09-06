class Solution
{
    public:

        int dp[31][1001], M = 1e9 + 7;
    int f(int dice, int faces, int target)
    {
        if (target < 0) return 0;
        
        if (dice < 0) return 0;
        
        if (dice == 0 && target == 0) return 1;
        
        
        if (dp[dice][target] != -1) return dp[dice][target] % M;
        
        
        int ans = 0;
        
        
        for (int i = 1; i <= faces; i++)
        {
            ans += f(dice - 1, faces, target - i);
            ans %= M;
        }
        
        
        return dp[dice][target] = ans % M;
    }
    int numRollsToTarget(int dice, int faces, int target)
    {
        memset(dp, -1, sizeof(dp));
        return f(dice, faces, target);
    }
};