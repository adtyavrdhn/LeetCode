class Solution {
public:
    int minDeletions(string s) 
    {
      unordered_map<char,int> mpp;
        
        for(auto c : s)
        {
            mpp[c]++;
        }
        
        unordered_set<int> st;
        
        int count = 0;
        
        for(auto i : mpp)
        {
            while(i.second > 0 && st.find(i.second)!=st.end())
            {
                i.second--;
                count++;
            }
            st.insert(i.second);
        }
        
        return count;
    }
};