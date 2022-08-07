class Solution
{
    public:
        vector<char> chars = { 'a',
            'e',
            'i',
            'o',
            'u' };
    int m = 1e9 + 7;
    
    int dp[26][20009];
    int countVowelPermutation(int n)
    {
        memset(dp,-1,sizeof(dp));

        int res = 0;

        for (int i = 0; i < chars.size(); i++)
        {
            res = (res % m + f(chars[i],n-1) % m) % m;
        }

        return res % m;
    }
    int f(char c, int n)
    {
        if (n == 0)
        {
            return 1;
        }

        if (dp[c - 'a'][n] != -1)
        {
            return dp[c - 'a'][n];
        }

        long long res = 0;

        if(c=='a')
        {
            res= (res%m + f('e',n-1)%m)%m;
            
        }
        if(c=='e')
        {
            res=(res%m + f('a',n-1)%m + f('i',n-1)%m)%m;
            
        }
        if (c == 'i')
        {
            res = (res % m + f('a', n - 1) % m + f('e', n - 1) % m + f('o', n - 1) % m + f('u', n - 1) % m) % m;
        }
        if (c == 'o')
        {
            res = (res % m + f('i', n - 1) % m + f('u', n - 1) % m) % m;
        }
        if (c == 'u')
        {
            res = (res % m + f('a', n - 1) % m) % m;
        }

        return dp[c - 'a'][n] = res % m;
    }
};