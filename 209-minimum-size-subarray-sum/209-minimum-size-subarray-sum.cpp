class Solution {
public:
    int minSubArrayLen(int k, vector<int>& arr)
    {   
        int i=0;
        int j=0;
        int n = arr.size();
        
        int res = INT_MAX;
        int sum = 0;
        
        for(;i<n;i++)
        {
            sum+= arr[i];
            
            while(sum>=k)
            {
                res = min(res,i-j+1);
                sum-= arr[j];
                j++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};