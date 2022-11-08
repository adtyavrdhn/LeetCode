class Solution {
public:
    string makeGood(string s) 
    {
        stack<char> st;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(st.empty() || abs(st.top()-s[i])!=32)
                st.push(s[i]);
            else
                st.pop();
        }
        
        string res;
        while(!st.empty())
        {
            res+= st.top();
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};