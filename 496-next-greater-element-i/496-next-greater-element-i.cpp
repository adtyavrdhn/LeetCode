class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        stack<int> st;
        unordered_map<int,int> mpp;
        
        for(int i=nums2.size()-1;i>=0;i--) {
            while(!st.empty() && st.top()<=nums2[i])
                st.pop();
            
            mpp[nums2[i]]= st.empty() ? -1 : st.top();
            
            st.push(nums2[i]);
        }
        
        vector<int> ans;
        for(int i=0;i<nums1.size();i++) 
            ans.push_back(mpp[nums1[i]]);
        return ans;
    }
};