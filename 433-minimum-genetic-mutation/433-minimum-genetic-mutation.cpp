class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        unordered_set<string> s(bank.begin(),bank.end());
        
        queue<string> q;
        q.push(start);
        
        int count = 0;
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                string curr = q.front();
                q.pop();
                
                if(curr==end)
                    return count;
                
                for(int j=0;j<curr.size();j++)
                {
                    
                    for(char c='A';c<='T';c++)
                    {
                        string temp = curr;
                        temp[j]=c;
                        
                        if(s.find(temp)!=s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
            count++;
        }
        
        return -1;
    }
};