class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        set<int> st;
        
        for(auto i : nums)
        {
            st.insert(i);
        }
        
        int n = nums.size();
        
        return n>st.size();
    }
};