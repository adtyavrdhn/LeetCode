class Solution {
public:
    int countSubstrings(string s)
    {
        int res = 0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(ispall(s,i,j))
                    res++;
            }
        }
        
        return res;
    }
    bool ispall(string& s, int i, int j)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        
        return true;
    }
};