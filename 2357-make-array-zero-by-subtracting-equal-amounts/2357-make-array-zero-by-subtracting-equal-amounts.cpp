class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        set<int> st;
        
        for(auto i : nums)
        {
            if(i!=0)
            st.insert(i);
        }
            
        
        return st.size();
    }
};