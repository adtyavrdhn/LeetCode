class Solution {
public:
    set<string> st;
    unordered_map<string,bool> mpp;
    vector<string> wordBreak(string s, vector<string>& dict) 
    {
        for(auto i : dict)
        {
            mpp[i]=true;
        }
        
        f(s,dict,0,"");
        
        vector<string> res(st.begin(),st.end());
        
        return res;
    }
    void f(string s, vector<string>&dict, int i,string t)
    {
        if(i>=s.size())
        {
            st.insert(t.substr(0,t.size()-1));
            return;
        }
        
        for(int j=i;j<s.size();j++)
        {
            string k = s.substr(i,j-i+1);
            
            if(mpp[k])
            {
                 f(s,dict,j+1,t+k+" ");
            }
        }
    }
};