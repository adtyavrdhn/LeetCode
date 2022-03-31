class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
        int n = words.size();
        vector<vector<bool>> mpp(n,vector<bool>(26,false));
        
        for(int i=0;i<n;i++)
        {
            for(auto j : words[i])
            {
                mpp[i][j-'a']=true;
            }
        }
        
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                bool ok = true;
                
                for(int k=0;k<26;k++)
                {
                    if(mpp[i][k]&&mpp[j][k])
                    {
                        ok = false;
                        break;
                    }
                }
                
                int len = words[i].length()*words[j].length();
                if(ok && len>res)
                res=len;
            }
        }
        
        return res;
    }
};