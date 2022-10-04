class Solution
{
    public:
    string largestNumber(vector<int> &cost, int target)
    {
        int n = cost.size();
        
        vector<vector<string>> dp(n, vector<string> (target+1,"-1"));
        
        return f(cost, target,0,dp);
    }
    string f(vector<int> &cost, int target, int index,vector<vector<string>>&dp)
    {
        if (target == 0)
        {
            return "";
        }
        
        if(index>= cost.size() || target<0)
        {
            return "0";
        }
        
        if(dp[index][target]!="-1")
            return dp[index][target];
        
        
        string res;
        
        string a,b;
        
        a = f(cost,target-cost[index],0,dp);
        b = f(cost,target,index+1,dp);
        
        if(a=="0" || b=="0") // one answer is invalid return the other
        {
           return dp[index][target] = a=="0" ? b : a+to_string(index+1);
        }
        else
        {
            a += to_string(index+1);
            
            if(a.size() == b.size())
            {
                 return dp[index][target] = max(a,b);
            }
            else if(b.size() > a.size())
            {
                return dp[index][target] = b;
            }
        }
        return dp[index][target]=a;
    }
};