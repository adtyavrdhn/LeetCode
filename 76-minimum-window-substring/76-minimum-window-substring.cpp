class Solution
{
    public:
        string minWindow(string s, string t)
        {
            if (s.length() < t.length())
                return "";

            int n = s.size();
            unordered_map<char, int> mpp;

            int i = 0, j = 0;

            for (int i = 0; i < t.size(); i++)
            {
                mpp[t[i]]++;
            }

            int count = mpp.size();
            int res = INT_MAX;

            string ans = "";

            while (j < n)
            {
                mpp[s[j]]--;
                if (mpp[s[j]] == 0)
                    count--;

                if (count == 0)
                {
                    while (count == 0)
                    {
                        if (j - i + 1 < res)
                        {
                            res = j - i + 1;
                            ans = s.substr(i, res);
                        }

                        mpp[s[i]]++;

                        if (mpp[s[i]] == 1)
                        {
                            count++;
                        }

                        i++;
                    }
                }
                j++;
            }
            
            if(res == INT_MAX)
            {
                return "";
            }
            return ans;
        }
};