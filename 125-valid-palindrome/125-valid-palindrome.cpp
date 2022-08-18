class Solution {
public:
    bool isPalindrome(string s) 
    {
        string t;
        int n = s.size();
        
        
        for(int i=0;i<n;i++)
        {
            if(isalnum(s[i]))
            {
                t.push_back(s[i]);
            }
        }
        
        transform(t.begin(),t.end(),t.begin(),::tolower);
        
        // cout<<t<<endl;
        
        int i=0,j=t.size()-1;
        
        while(i<j)
        {
            if(t[i]!=t[j])
            {
                return false;
            }
            
            i++,j--;
        }
        
        return true;
    }
};