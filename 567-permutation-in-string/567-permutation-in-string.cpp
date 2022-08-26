class Solution
{
    public:
        bool checkInclusion(string s, string t)
        {
            unordered_map<char, int> mpp;
            
            int n = t.size();
            
            for (auto i: s)
                mpp[i]++;

            int count = mpp.size();
            int k = s.size();

            int i = 0, j = 0;

            while (j < n)
            {
                mpp[t[j]]--;

                if (mpp[t[j]] == 0)
                {
                    count--;
                }

                if (j - i + 1 == k)
                {
                    if (count == 0)
                        return true;

                    if (mpp.find(t[i]) != mpp.end())
                        mpp[t[i]]++;

                    if (mpp[t[i]] == 1)
                        count++;

                    i++;
                }
                
                j++;
            }

            return false;
        }
};