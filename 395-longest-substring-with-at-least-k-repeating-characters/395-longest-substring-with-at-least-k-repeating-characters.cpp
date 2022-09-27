class Solution
{
    public:
        int longestSubstring(string s, int k)
        {
            int n = s.size();
            return f(s, k, 0, n);
        }

    int f(string s, int k, int start, int end)
    {
        if (end - start < k)
            return 0;

        unordered_map<char, int> mpp;

        for (int i = start; i < end; i++)
        {
            mpp[s[i]]++;
        }

        for (int i = start; i < end; i++)
        {
            if (mpp[s[i]] < k)
            {
                int bp = i + 1;

//                 while (bp < end && mpp[s[bp]] < k)
//                     bp++;

                return max(f(s, k, start, i), f(s, k, bp, end));
            }
        }
        return end - start;
    }
};