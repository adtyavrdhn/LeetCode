class Solution {
public:
    string breakPalindrome(string s)
    {
        int n = s.size();
        if(n==1)
            return "";
        int count = 0;
      
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!='a')
            {
                s[i]='a';
                return s;
            }
        }
        
            s[n-1]='b';
        
        
        return s;
    }
};