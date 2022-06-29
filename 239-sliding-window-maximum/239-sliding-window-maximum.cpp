class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
      int n = nums.size();
        
        int i=0,j=0;
        
         list<int> q;
        
        vector<int> res;
        
        while(j<n)
        {
            while(!q.empty() && q.back() < nums[j])
                q.pop_back();
            
            q.push_back(nums[j]);
            
            if((j-i+1)==k)
            {
                int maxi = q.front();
                
                if(nums[i]==maxi)
                    q.pop_front();
                
                res.push_back(maxi);
                i++;
            }
            
            j++;
        }
        
        return res;
    }
};