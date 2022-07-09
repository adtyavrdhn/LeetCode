class Solution
{
    public:
        int maxResult(vector<int> &nums, int k)
        {
            int n = nums.size();
            
            list<int> q;
            
            q.push_back(0);
            
            for (int i = 1; i < n; ++i)
            {
              nums[i] = nums[q.front()] + nums[i];
                
               while(!q.empty() && nums[q.back()] <= nums[i]) 
              {
                q.pop_back();
              }
                
                q.push_back(i);
                
               if (i - q.front() >= k) q.pop_front(); 
            }

            return nums[n - 1];
        }
    
    // https://leetcode.com/problems/jump-game-vi/discuss/1260843/C%2B%2BJavaPython-DP-and-Decreasing-Deque-Clean-and-Concise-Time-O(N)-Space-O(K)
};