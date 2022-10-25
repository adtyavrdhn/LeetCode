class Solution
{
    public:
        bool PredictTheWinner(vector<int> &nums)
        {
            int n = nums.size();
            return f(nums, 0, n - 1, true, 0, 0);
        }
    bool f(vector<int> &nums, int i, int j, bool turn, int one, int two)
    {
        if (i > j)
        {
            return one >= two;
        }
        
        int res = -1;

        if (turn)
        {
            if(f(nums, i + 1, j, !turn, one + nums[i], two) | f(nums, i, j - 1, !turn, one + nums[j], two))
                res = true;
            
            if(res == -1)
                res = false;
        }
        else
        {
            if(!f(nums, i + 1, j, !turn, one, two + nums[i]) | !f(nums, i, j - 1, !turn, one, two + nums[j]))
                res = false;
            
            if(res == -1)
                res = true;
        }

        return res;
    }
};