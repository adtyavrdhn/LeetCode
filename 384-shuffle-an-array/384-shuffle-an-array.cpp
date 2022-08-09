class Solution
{
    public:
        vector<int> org;
    vector<int> arr;
    Solution(vector<int> &nums)
    {
        org = nums;
        arr = nums;
    }

    vector<int> reset()
    {
        arr = org;
        return arr;
    }

    vector<int> shuffle()
    {
        int n = arr.size();

        for (int i = n - 1; i > 0; i--)
        {
            int j = rand() % (i + 1);
            swap(arr[i], arr[j]);
        }
        
        return arr;
    }
};

/**
 *Your Solution object will be instantiated and called as such:
 *Solution* obj = new Solution(nums);
 *vector<int> param_1 = obj->reset();
 *vector<int> param_2 = obj->shuffle();
 */