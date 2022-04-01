class Solution {
public:
    string reverseVowels(string s) 
    {
        int n = s.size();
        int left  = 0;
        int right = n-1;
        
        while(left<=right)
        {
          while(left < right && !isvowel(s[left])) left++;
          while(left<right && !isvowel(s[right])) right--;
            
            if(isvowel(s[left])&&isvowel(s[right])) swap(s[left],s[right]);
            
            left++;
            right--;
        }
        
        return s;
    }
    
    bool isvowel(char x)
    {
        x = tolower(x);
        if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u') return true;
        
        return false;
    }
};