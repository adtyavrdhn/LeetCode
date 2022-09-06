class Solution
{
    public:
    int mod = 1e9 + 7;
    int dp[5005][7][16];
    int dieSimulator(int n, vector<int> &rolls) 
    {
        memset(dp,-1,sizeof(dp));
        return f(n,rolls,0,0);
    }
    int f(int n, vector<int> &rolls, int prev, int count)
    {
        if (n == 0)
        {
            return 1;
        }
        
        long long res = 0;
        
        if(dp[n][prev][count]!=-1)
            return dp[n][prev][count];

        for (int i = 1; i <= 6; i++)
        {
            if (i == prev)
            {
                if (count < rolls[i - 1])
                {
                    res += f(n - 1, rolls, prev, count + 1)%mod;
                }
            }
            else 
            {
               res+= f(n-1,rolls,i,1)%mod; 
            }
        }
        
        return dp[n][prev][count] = res%mod;
    }
};