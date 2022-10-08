class Solution {
public:
    int countSubstrings(string s)
    {
        int res = 0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                string temp = s.substr(i,j-i+1);
                
                if(ispall(temp))
                    res++;
            }
        }
        
        return res;
    }
    bool ispall(string& s)
    {
        int i=0, j=s.size()-1;
        
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        
        return true;
    }
};