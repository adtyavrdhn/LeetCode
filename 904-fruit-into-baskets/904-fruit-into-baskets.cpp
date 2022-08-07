class Solution
{
    public:
        int totalFruit(vector<int> &fruits)
        {
            int n = fruits.size();

            int j = 0;

            unordered_map<int, int> mpp;
            int i = 0;

            int res = 0;

            while (j < n)
            {
                mpp[fruits[j]]++;

                while (i < n && mpp.size() > 2)
                {
                    mpp[fruits[i]]--;

                    if (mpp[fruits[i]] == 0)
                    {
                        mpp.erase(fruits[i]);
                    }

                    i++;
                }

                res = max(res, j - i + 1);
                j++;
            }

            return res;
        }
};