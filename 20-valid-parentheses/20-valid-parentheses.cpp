class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i: s){
            if(i == '(' || i =='{' || i=='[')
                st.push(i);
            else{
                if(st.empty()) return false;
                else if(i == ')' and st.top() == '(')    st.pop();
                else if(i == ')' and st.top() != '(')   return false;
                else if(i == '}' and st.top() == '{')    st.pop();
                else if(i == '}' and st.top() != '{')   return false;
                else if(i == ']' and st.top() == '[')    st.pop();
                else if(i == ']' and st.top() != '[')   return false;
            }
        }
        return st.empty();
    }
};