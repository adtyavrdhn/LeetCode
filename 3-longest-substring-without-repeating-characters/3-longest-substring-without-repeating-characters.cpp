class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char,int> mpp;
        int res=0;
        int left = 0, right = 0, n = s.size();
        
        while(right < n)
        {
            if(mpp.find(s[right])!=mpp.end())
            {
                left = max(left, mpp[s[right]]+1);
            }
             res = max(res,right-left + 1);
            mpp[s[right]]=right;
            right++;
        }
        
        return res;
        
    }
};