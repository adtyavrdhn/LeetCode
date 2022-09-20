class Solution
{
    public:
        string minWindow(string s, string t)
        {
            if (s.length() < t.length())
            {
                return "";	// impossible task
            }

            int n = s.size();
            unordered_map<char, int> mpp;

            int i = 0, j = 0;

            for (int i = 0; i < t.size(); i++)
            {
                mpp[t[i]]++;	// adding the characters frequency to our map
            }

            int count = mpp.size();
            int res = INT_MAX;

            string ans = "";

            while (j < n)
            {
                mpp[s[j]]--;	// if we find a character that was a part of t and hence in our map, taking it into our substring will mean one less character to find in the substring
                if (mpp[s[j]] == 0)
                    count--;	// we found all instances of a character needed and that means one less character to find

               	// we found all our characters

                while (count == 0)	// now we shrink our window
                {
                    if (j - i + 1 < res)	// if the current window is smaller
                    {
                        res = j - i + 1;
                        ans = s.substr(i, res);
                    }

                    if (mpp.find(s[i]) != mpp.end())
                        mpp[s[i]]++;	// shrinking the window means we are removing characters from our substring and so if that character was a part of the string t, that means we need to find that character elsewhere to make up for it

                    if (mpp[s[i]] == 1)
                    {
                        count++;	// we ended up removing a character from our answer substring, which would mean we need to make up for it and find it ahead
                    }

                    i++;
                }

                j++;
            }

            if (res == INT_MAX)
            {
                return "";
            }
            return ans;
        }
};