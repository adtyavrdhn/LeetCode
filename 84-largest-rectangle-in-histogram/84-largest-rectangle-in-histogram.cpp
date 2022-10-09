class Solution {
public:
    int largestRectangleArea(vector<int>& arr) 
    {
        stack<int> st;
        
        int n = arr.size();
        
        int res = 0;
        
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || arr[st.top()]>=arr[i]))
            {
                int height = arr[st.top()]; // the last height which will be stored in variable height will keep the tower we are currently calculating for
                st.pop();
                
                int width = 0;
                
                if(st.empty())
                    width = i;
                
                else width = i-st.top()-1; // st.top() is left smaller index while i is the right smaller index
                
                res = max(res, width*height);
                
            }
            st.push(i);
        }
        
        return res;
    }
};