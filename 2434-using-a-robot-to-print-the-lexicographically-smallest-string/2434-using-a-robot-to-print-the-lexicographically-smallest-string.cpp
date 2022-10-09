class Solution {
public:
    string robotWithString(string s) 
    {
        int n = s.size();
        
        vector<char> suff(n,s[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {
            suff[i]= min(suff[i+1],s[i]);
        }
        
        string res;
        stack<char> st;
        
        for(int i=0;i<n;i++)
        {
           while(!st.empty() && suff[i]>=st.top())
           {
               res.push_back(st.top());
               st.pop();
           }
            st.push(s[i]);
        }
        
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        
        return res;
    }
};