class Solution
{
    public:
        vector<int> mostCompetitive(vector<int> &nums, int k)
        {
            stack<int> s;
            
            
            for (int i = 0; i < nums.size(); i++)
            {
                if (s.empty()) 
                    s.push(nums[i]);
                
                else if (nums[i] < s.top())
                {
                    while (k - s.size() < nums.size() - i)
                    {
                        if (s.size() && s.top() > nums[i]) 
                            s.pop();
                        
                        else 
                            break;
                    }
                    
                    s.push(nums[i]);
                }
                
                else if (s.size() < k) s.push(nums[i]);
            }
            
            vector<int> res;
            
            while (s.size())
            {
                res.push_back(s.top());
                s.pop();
            }
            
            reverse(res.begin(), res.end());
            
            return res;
        }
};