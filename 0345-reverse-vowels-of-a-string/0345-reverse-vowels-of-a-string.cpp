class Solution {
public:
    string reverseVowels(string s) 
    {
        int n = s.size();
        int i=0,j=n-1;
        
        while(i<j)
        {
            while(i<j && notvow(s[i]))
                i++;
            
            while(i<j && notvow(s[j]))
                j--;
            
            swap(s[i++],s[j--]);
        }
        
        return s;
    }
    bool notvow(char c)
    {
        string s = "aeiouAEIOU";
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==c)
                return false;
        }
        return true;
    }
};