class Solution
{
    public:
    #define ll long long
    int dp[101][23][101];
    int inf = 10000000;
        int minCost(vector<int> &houses, vector<vector< int>> &cost, int m, int n, int target) 
        {
             memset(dp,-1,sizeof(dp));
            
            int res = f(houses,cost,0,target,0,n);
            
            return res == inf ? -1 : res;
        }
    int f(vector<int> &houses, vector< vector< int>> &cost, int index, int target, int last,int n)
    {
        if (target < 0)
        {
            return inf;
        }

        if (index >= houses.size())
        {
            return target == 0 ? target : inf;
        }
        
        if(dp[index][last][target]!=-1)
        {
            return dp[index][last][target];
        }
        
        if (houses[index])
        {
            if (last != houses[index])
            {
                target -=1;
            }
            
            return f(houses,cost,index+1,target,houses[index],n);
        }
        
        int res = inf;
        
        for(int j=1;j<=n;j++)
        {
            
            res = min(res, cost[index][j-1]+f(houses,cost,index+1,target-(last!=j),j,n));
        }
        
        return dp[index][last][target] = res;
    }
};