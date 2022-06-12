class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& m) {
        int n = s.length(), k = sub.length();
        
        unordered_map<char,unordered_set<char>> mp;
        
        for(int i=0;i<m.size();i++)
            mp[m[i][0]].insert(m[i][1]);
        

        for(int i=0;i<=n-k;i++)
        {
            int flag = 0;
            
            for(int j=0;j<k;j++)
            {
                char x = s[i+j], y = sub[j];
                
                if(y==x || mp[y].find(x)!=mp[y].end()) continue;
                
                else
                {
                    flag = 1;
                    break;
                }
            }
            
            if(flag==0) return true;
        }
        return false;
    }
};