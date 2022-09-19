class Solution {
public:
    int longestValidParentheses(string s) 
    {
        if(s.size()<2)
            return 0; // no balanced string possible
        
        stack<int> st;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                // current bracket is a closing bracket
                
                if(!st.empty() && s[st.top()]=='(')
                {
                    st.pop();
                }
                else
                    st.push(i);
            }
        }
        
        // if(st.empty())
        //     return s.size();
        
        int res = 0;
        
        int last = s.size();
        
        while(!st.empty())
        {
            res = max(res, last-st.top()-1);
            last = st.top();
            st.pop();
        }
        
        res = max(res, last);
        
        return res;
    }
};