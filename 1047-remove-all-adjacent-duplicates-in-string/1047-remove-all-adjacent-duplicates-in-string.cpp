class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char>st;
        
        st.push(s[0]);
        
        int n =s.length();
        
        for(int i=1;i<n;i++)
        {
            //char a1 = st.top();
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(st.top()==s[i])  
            {
                st.pop();
            }
            else
            {
            st.push(s[i]);
                }
        }
        
        
        string ans = "";
        while(!st.empty())
        {
            ans +=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        
        return ans;
    }
};