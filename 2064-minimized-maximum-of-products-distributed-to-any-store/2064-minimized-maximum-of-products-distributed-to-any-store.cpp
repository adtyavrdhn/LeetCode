class Solution {
public:
    int x;
    int minimizedMaximum(int n, vector<int>& q) 
    {
        int left  = 1;
        int right = (int)1e9;
        int res = 0;
        
        // if x is the number which shows the maximum number of products that can be given to a store at any time we need to minimize it
        // sum of quantities <= n(total stores) * x should be the condition for the distribution to be feasible
        
        // int sum = 0;
        // for(int i=0;i<size(q);i++)
        //     sum+=q[i];
        
        while(left <= right)
        {
            int mid = left+(right-left)/2;
            
            if(feasible(mid,n,q))
            {
                // let's search in the left half to see if we can go lower than the current mid
                res=mid;
                right=mid-1;
            }
            
            else
                left = mid + 1;
        }
        
        return res;
    }
    
    bool feasible(int x, int n, vector<int>& q)
    {
        for(int i=0;i<size(q);i++)
        {
            n-= ceil(q[i]/(x*1.0));
            
            if(n<0)
                return false;
        }
        return true;
        
        
    }
};