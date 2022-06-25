class Solution
{
    public:
    int mod = 1000000007;
    long solve(int n, int last, int prevLast, int i, vector<vector<vector<int>>>&dp)
    {
        if (i == n) return 1;
        
        long res = min(last, prevLast)<0 ? -1 :dp[last][prevLast][i];
        if(res!=-1) return res;
        
        res = 0;
        
        for (int j=1;j<=6;j++)
        {
            if (j == last || j == prevLast || (last != -1 && (__gcd(j, last) != 1))) continue;
            res = (res + solve(n, j, last, i + 1,dp))%mod;
        }
        
        if(min(last, prevLast)>=0) {
            dp[last][prevLast][i]=res;
        }
        
        return res;
    }

    int distinctSequences(int n)
    {
        vector<vector<vector<int>>> dp(7,vector<vector<int>> (7,vector<int> (n+1,-1)));
        return solve(n, -1, -1, 0,dp);
    }
};