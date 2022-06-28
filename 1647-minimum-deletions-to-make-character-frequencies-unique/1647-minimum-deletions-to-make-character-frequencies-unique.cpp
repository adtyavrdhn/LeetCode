class Solution
{
    public:
        int minDeletions(string s)
        {
            vector<int> mpp(26, 0);
            for (char c: s)
            {
                mpp[c - 'a']++;
            }

            int count = 0;
            
            unordered_set<int> st;
            
            for (int i = 0; i < 26; i++)
            {
                while (mpp[i] && st.find(mpp[i]) != st.end())
                {
                    mpp[i]--;
                    count++;
                }
                st.insert(mpp[i]);
            }

            return count;
        }
};