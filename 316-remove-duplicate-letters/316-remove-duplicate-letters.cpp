class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        unordered_map<char,int> freq(26);
        unordered_map<char,bool> visited(26);
        
        string res;
        
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]]++;
        }
        
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]]--;
            if(!visited[s[i]])
            {
                while(res.size() && res.back() > s[i] && freq[res.back()]>0)
                {
                    visited[res.back()]=false;
                    res.pop_back();
                }
                
                res.push_back(s[i]);
                visited[s[i]]=true;
            }
        }
        
        return res;
    }
};