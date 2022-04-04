class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        
        if(sum%2 != 0) return false;
        else return f(n,sum/2,nums);
        
    }
    
bool f(int n, int k, vector<int> &arr) 
{

    vector<bool> prev(k+1,0), curr(k+1,0);
    prev[0] = curr[0] = true;
   if(arr[0]<=k) prev[arr[0]] = true;
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=k;j++)
        {
           bool ntake = prev[j];
           bool take = false;
          if(arr[i]<=j)
          take = prev[j-arr[i]];
       curr[j] = take || ntake;
        }
        
        prev = curr;
    }
    
    return prev[k];
}
    
};