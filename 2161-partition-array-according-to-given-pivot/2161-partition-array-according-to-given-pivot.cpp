class Solution
{
    public:
        vector<int> pivotArray(vector<int> &nums, int pivot)
        {
            int n = nums.size();
            
            vector<int> res;
            
            int count = 0;
            
            for (int num: nums)
            {
                if (num < pivot)
                {
                    res.push_back(num);
                }
                if (num == pivot) count++;
            }
            
            while (count--)
            {
                res.push_back(pivot);
            }
            
            for (int num: nums)
            {
                if (num > pivot)
                {
                   res.push_back(num);
                }
            }
            return res;
        }
};