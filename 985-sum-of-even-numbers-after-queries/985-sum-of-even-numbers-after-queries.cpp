class Solution
{
    public:
        vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector< int>> &queries)
        {
            int n = queries.size();

            vector<int> res;

            int sum = 0;

            for (auto i: nums)
            {
                if (i % 2 == 0)
                    sum += i;
            }

           	// cout<<sum<<endl;

            for (int i = 0; i < queries.size(); i++)
            {
                int index = queries[i][1];
                int x = nums[index];
                int nx = x + queries[i][0];

                if (nx % 2 == 0)
                {
                    sum += nx;
                }

                if (x % 2 == 0)
                {
                    sum -= x;
                }

                // cout << index << " " << x << " " << nx << " " << sum << endl;

                nums[index] = nx;
                res.push_back(sum);
            }

            return res;
        }
};