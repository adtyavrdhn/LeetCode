class Solution
{
    public:
        vector<int> majorityElement(vector<int> &nums)
        {
            int n = nums.size();

            vector<int> res;

            sort(nums.begin(), nums.end());

            int num = nums[0];

            int count = 1;

            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] == num)
                {
                    count++;
                }
                else
                {
                    if (count > (n / 3))
                    {
                        res.push_back(num);
                    }
                    num = nums[i];
                    count = 1;
                }
            }
            if (count > (n / 3))
            {
                res.push_back(num);
            }

            return res;
        }
};