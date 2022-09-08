class Solution
{
    public:
        
    int f(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (res.empty() || nums[i] > res.back()) res.push_back(nums[i]);
            else
            {
                int idx = lower_bound(begin(res), end(res), nums[i]) - begin(res);
                res[idx] = nums[i];
            }
        }
        return res.size();
    }

    int minOperations(vector<int> &target, vector<int> &arr)
    {
        unordered_map<int, int> mpp;
        
        vector<int> nums;
        for (int i = 0; i < target.size(); ++i) 
        {
            mpp[target[i]] = i;
        }
        
        
        for (int i = 0; i < arr.size(); ++i)
        {
            if (mpp.find(arr[i]) != end(mpp)) nums.push_back(mpp[arr[i]]);
        }
            
        
        
        return target.size() - f(nums);
    }
};