class Solution
{
    public:
        int minimumLengthEncoding(vector<string> &words)
        {
            string ans;
            sort(words.begin(), words.end(), [](string &a, string &b)
            {
                return a.size() > b.size();
	});
            for (string &s: words)
                if (ans.find(s + "#") == string::npos) ans += s + "#";
            
            
            return ans.size();
        }
};