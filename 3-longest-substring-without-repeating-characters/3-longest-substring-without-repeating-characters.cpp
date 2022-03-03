class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256,-1);
        
        int n = s.size();
        int right = 0;
        int left = 0;
        int len=0;
        while(right < n)
        {
            if(mpp[s[right]]!=-1)
            left = max(left,mpp[s[right]]+1);
            
            mpp[s[right]]=right;
            
            len = max(right-left+1,len);
            right++;
            
                
        }
        
        return len;
    }
};