class Solution {
public:
    int dp[601][101][101];
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        int sz = 0;
        sz = strs.size();
        
        for(int i=0;i<601;i++)
        {
            for(int j=0;j<=100;j++)
            {
                for(int k=0;k<=100;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        
        return f(strs,0,m,n);
    }
    int f(vector<string>& strs, int index, int m, int n)
    {
        if(index==strs.size())
        {
            return 0;
        }
        
        if(dp[index][m][n]!=-1)
            return dp[index][m][n];
        
        pair<int,int> t = count_zo(strs[index]);
        int pick = INT_MIN;
        
        if(t.first <= m && t.second <= n)
        {
          pick = 1 + f(strs,index+1,m-t.first,n-t.second);
        }
        
        int npick = f(strs,index+1,m,n);
        
        return dp[index][m][n] = max(pick,npick);
    }
    pair<int,int> count_zo(string &s)
    {
        int z =0;
        int o = 0;
        
        for(auto c : s)
        {
            if(c=='0')
                z++;
            else
                o++;
        }
        
        return make_pair(z,o);
    }
};