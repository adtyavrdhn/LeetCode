class Solution
{
    public:
        int maxScore(vector<int> &cards, int k)
        {
            int n = cards.size();

            int sum = 0;

            int tsum = 0;
            for (auto i: cards)
                tsum += i;

            for (int i = 0; i < n - k; i++)
                sum += cards[i];

            int res = sum;

            for (int i = n - k; i < n; i++)
            {
                sum -= cards[i - (n - k)];
                sum += cards[i];

                res = min(res, sum);
            }

            // cout << tsum << " " << res << endl;

            return tsum - res;
        }
};