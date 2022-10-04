class Solution
{
    public:
    string largestNumber(vector<int> &cost, int target)
    {
        int n = cost.size();
        
        vector<string> dp(target+1,"-1");
        
        return f(cost, target,0,dp);
    }
    string f(vector<int> &cost, int target, int index,vector<string>&dp)
    {
        if (target == 0)
        {
            return "";
        }
        
        if(index>= cost.size() || target<0)
        {
            return "0";
        }
        
        if(dp[target]!="-1")
            return dp[target];
        
        
        string res;
        
        string a,b;
        
        a = f(cost,target-cost[index],0,dp);
        b = f(cost,target,index+1,dp);
        
        if(a=="0" || b=="0") // one answer is invalid return the other
        {
           return dp[target] = a=="0" ? b : a+to_string(index+1);
        }
        else
        {
            a += to_string(index+1);
            
            if(a.size() == b.size())
            {
                 return dp[target] = max(a,b);
            }
            else if(b.size() > a.size())
            {
                return dp[target] = b;
            }
        }
        return dp[target]=a;
    }
};