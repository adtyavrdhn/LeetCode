class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        
        
        int n = nums.size();
        int res = 0;
        
        int cdiff = INT_MAX;
        
        for(int i=0;i<n-2;i++)
        {
            int low = i+1, high = n-1;
            
            while(low<high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                
                if(abs(target-sum) < cdiff)
                {
                    res = sum;
                    cdiff = abs(target-sum);
                }
                
                if(sum==target)
                {
                    return sum;
                }
                else if(sum<target)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
        
        return res;
    }
};