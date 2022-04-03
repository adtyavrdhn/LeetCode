class Solution {
public:
    int maximumCandies(vector<int>& c, long long k) 
    {
        int left = 1 ;
        int right = 1e9;
        int res = INT_MIN;
        
        int n = c.size();
        long long sum = 0;
        
//         for(int i=0;i<n;i++)
//         {
//             sum+=c[i];
    
//         }
        
//          if(k > sum) return 0;
        
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            
            if(isfeasible(c,k,mid))
            {
                res = max(res,mid);
                left = mid+1;
            }
            
            else
            {
                right = mid - 1;
            }
        }
        
        return res == INT_MIN? 0 : res;
    }
    
    bool isfeasible(vector<int> &c, long long k, int candy)
    {
        long long count = 0;
        for(int i=0;i<c.size();i++)
        {
            count+= c[i]/candy;
        }
        
        if(count>=k)
            return true;
        else
            return false;
    }
};