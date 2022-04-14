class Solution {
public:
    int ladderLength(string bword, string eword, vector<string>& words) 
    {
        unordered_set<string> w(words.begin(),words.end());
        queue<string> q;
        q.push(bword);
        
        int count = 0;
        
        while(!q.empty())
        {
            count++;
            
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                string curr = q.front();
                q.pop();
                
                if(curr==eword) return count;
                
               
                for(int j=0;j<curr.size();j++)
                {
                    for(char c='a';c<='z';c++)
                    {
                        string temp = curr;
                        temp[j]=c;
                        
                        if(w.find(temp)!=w.end())
                        {
                            q.push(temp);
                            w.erase(temp);
                          
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};