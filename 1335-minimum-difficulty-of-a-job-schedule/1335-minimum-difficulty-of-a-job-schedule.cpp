class Solution {
public:
    int dp[11][301][1005];
    int minDifficulty(vector<int>& jobs, int d) 
    {
        int res = 0;
        memset(dp,-1,sizeof(dp));
        res = f(jobs,d,0,0);
        
        return res == 1e9 ? -1 : res;
    }
    int f(vector<int>&jobs, int d, int index, int maxm)
    {
        if(index>=jobs.size())
        {
            if(d==0)
            {
                return maxm;
            }
            return 1e9;
        }
        
        if(dp[d][index][maxm]!=-1)
        {
            return dp[d][index][maxm];
        }
        
        int ntake = 1e9;
        int take = f(jobs,d,index+1,max(jobs[index],maxm));
        
        if(d>=1)
        ntake = maxm + f(jobs,d-1,index+1,jobs[index]);
        
        return dp[d][index][maxm] = min(take,ntake);
    }
};