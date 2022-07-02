class Solution
{
    public:
        bool checkInclusion(string t, string s)
        {
            int n = s.size();
            int k = t.size();
            unordered_map<char, int> mpp;

            for (auto c: t)
            {
                mpp[c]++;
            }

            int count = mpp.size();

            int i = 0, j = 0;

            while (j < n)
            {
                mpp[s[j]]--;

                if (mpp[s[j]] == 0)
                    count--;

                if (j - i + 1 == k)
                {
                    if (count == 0)
                    {
                        return true;
                    }

                    if (mpp.find(s[i]) != mpp.end())
                        mpp[s[i]]++;

                    if (mpp[s[i]] == 1)
                    {
                        count++;
                    }

                    i++;
                }

                j++;
            }

            return false;
        }
};