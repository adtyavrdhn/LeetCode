class Solution {
public:
    int largestRectangleArea(vector<int>& arr) 
    {
        int n = arr.size();
        
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            
            left[i] = st.empty() ? 0 : st.top() + 1;
            
            st.push(i);
        }
        
        while(!st.empty())
            st.pop();
        
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            
            right[i] = st.empty() ? n-1 : st.top()-1;
            
            st.push(i);
        }
        
        int res = 0;
        for(int i=0;i<n;i++)
        {
            res = max(res,(right[i]-left[i]+1)*arr[i]);
        }
        
        return res;
    }
};