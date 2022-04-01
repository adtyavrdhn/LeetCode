class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int n = size(s);
        int left= 0;
        int right = n-1;
        
        while(left <= right)
        {
            swap(s[left++],s[right--]);
        }
    }
};