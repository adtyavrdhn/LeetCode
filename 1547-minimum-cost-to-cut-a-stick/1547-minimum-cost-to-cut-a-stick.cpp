class Solution {
public:
    int dp[101][101];
    int minCost(int n, vector<int>& cuts) 
    {
        int c = cuts.size();
        memset(dp,-1,sizeof(dp));
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        
        sort(cuts.begin(),cuts.end());
         
        return f(1,c,cuts); // at the first and last cut (i , j) (0 and n are on the edges)
    }
    int f(int i, int j, vector<int>&cuts)
    {
        if(i>j)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int res = INT_MAX;
        
        for(int k=i;k<=j;k++)
        {
            int cost = cuts[j+1] - cuts[i-1] + f(i,k-1,cuts) + f(k+1,j,cuts);
            res = min(res,cost);
        }
        
        return dp[i][j] = res;
    }
};