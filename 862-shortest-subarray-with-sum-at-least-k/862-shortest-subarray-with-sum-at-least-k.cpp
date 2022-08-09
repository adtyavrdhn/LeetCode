class Solution
{
    public:
        int shortestSubarray(vector<int> &nums, int k)
        {
            deque<pair<long long, long long>> dq;

            long long res = INT_MAX;
            long long sum = 0;

            for(long long j=0;j<nums.size();j++)
            {
                sum += nums[j];

                if (sum >= k)
                {
                    res = min(res, j + 1);
                }
                pair<long long, long long> curr = { INT_MIN,
                    INT_MIN
                };

                while (!dq.empty() && (sum - dq.front().second) >= k)
                {
                    curr = dq.front();
                    dq.pop_front();
                }

                if (curr.second != INT_MIN)
                {
                    res = min(res, j - curr.first);
                }

                while (!dq.empty() && sum <= dq.back().second)
                {
                    dq.pop_back();
                }

                dq.push_back({ j,
                    sum });

            }

            return res == INT_MAX ? -1 : res;
        }
};