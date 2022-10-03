class Solution
{
    public:
        vector<vector < string>> res;
    vector<vector < string>> partition(string s)
    {
        vector<string> temp;

        f(s, 0, temp);

        return res;
    }
    void f(string &s, int index, vector<string>& temp)
    {
        if (index >= s.size())
        {
            res.push_back(temp);
            return;
        }

        for (int i = index; i < s.size(); i++)
        {
            string k = s.substr(index, i - index + 1);

            if (ispall(s,index,i))
            {
                temp.push_back(k);

                f(s, i + 1, temp);
                
                temp.pop_back();
            }
        }
    }
   bool ispall(string &s, int low, int high) 
   {
        while (low < high) 
        {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
};