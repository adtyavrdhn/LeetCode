class Solution
{
    public:
        vector<int> platesBetweenCandles(string s, vector<vector < int>> &queries)
        {
            int n = s.size();

            vector<int> nextCandle(n, n), prevCandle(n, -1), prefixSum(n, 0);

            for (int i = 0; i < n; i++)
            {

                prevCandle[i] = (s[i] == '*') ? ((i == 0) ? prevCandle[i] : prevCandle[i - 1]) : i;
                nextCandle[n - i - 1] = (s[n - i - 1] == '*') ? ((i == 0) ? nextCandle[n - i - 1] : nextCandle[n - i]) : n - i - 1;

                prefixSum[i] = (i == 0) ? (s[i] == '*') : prefixSum[i - 1] + (s[i] == '*');
            }

            vector<int> answer;

            for (auto &query: queries)
            {

                int start = nextCandle[query[0]] > query[1] ? 0 : nextCandle[query[0]];
                int end = prevCandle[query[1]] < query[0] ? 0 : prevCandle[query[1]];

                answer.push_back(prefixSum[end] - prefixSum[start]);
            }

            return answer;
        }

   	// https://leetcode.com/problems/plates-between-candles/discuss/1586720/Intuition-Explained-oror-Prefix-Sum-and-Binary-Search-oror-C%2B%2B-Clean-Code
};