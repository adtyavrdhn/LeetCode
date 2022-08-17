class Solution {
public:
    int ladderLength(string start, string end, vector<string>& words) 
    {
        unordered_set<string> st(words.begin(),words.end());
        
        queue<string> q;
        q.push(start);
        
        
        int res = 1;
        
        while(!q.empty())
        {
            int size =  q.size();
            
            for(int i=0;i<size;i++)
            {
                auto t = q.front();
                q.pop();
                
                if(t==end)
                {
                    return res;
                }
                
                for(int j=0;j<t.size();j++)
                {
                    
                    string temp = t;
                    for(char c = 'a';c<='z';c++)
                    {
                        temp[j] = c;
                        if(st.find(temp)!=st.end())
                        {
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
                
            }
            
            res++;
        }
        
        return 0;
    }
};