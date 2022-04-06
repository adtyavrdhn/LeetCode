class Solution {
public:
    int mod = 1e9 + 7;
    int threeSumMulti(vector<int>& nums, int target) 
    {
        long long res = 0;
        sort(nums.begin(),nums.end());
        // unordered_map<int,int> mpp;
        int n = size(nums);
//       for(int i=0;i<n;i++)
//       {
//           mpp[nums[i]]++;
//       }
        
        int count = 0;
        
        for(int i=0;i<n-2;i++)
        {
            int T = target-nums[i];
            int lo = i+1;
            int hi = n-1;
              while(lo < hi)
             {
                int sum = nums[lo]+nums[hi];
                  
              if(sum < T)
                  lo++;
              else if(sum > T) 
                   hi--;
              else if(nums[lo]!=nums[hi])
              {
                      int left = 1;
                      int right = 1;
                   while(lo < hi && nums[lo]==nums[lo+1])
                   {
                       left++;
                       lo++;
                   }
                  
                  while(lo < hi && nums[hi]==nums[hi-1])
                  {
                      right++;
                      hi--;
                  }
                  
                  res+=left*right;
                  res%=mod;
                  
                  lo++;
                  hi--;
              }
                else
                 {
                      // M = hi - lo + 1
                    // contributed M*(M-1)/2 
                    // M = hi-lo + 1 because this is the window with same characters(sorted array remember?) so like [4,4,,4] will give us M = 3
                    res+=(hi-lo + 1)*(hi - lo)/2;
                    res%=mod;
                    break;
                 }
             }
                
          
        }
        // cout<<endl;
        return (int)res;
    }
};