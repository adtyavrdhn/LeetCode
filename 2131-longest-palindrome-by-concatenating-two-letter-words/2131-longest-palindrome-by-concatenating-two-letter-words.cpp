class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        map<string,int> mpp;
        
        for(auto i : words)
            mpp[i]++;
        
        
        int res = 0;
        
        bool flag = false;
        
        for(auto i : mpp)
        {
            string a = i.first;
            string b = i.first;
            reverse(b.begin(),b.end());
            
            if(a==b)
            {
                if(i.second%2!=0)
                {
                    if(!flag)
                        res+= i.second*2,flag = true;
                    else
                        res+= (i.second-1)*2;
                }
                else
                {
                    res+= i.second*2;
                }
            }
            else if(mpp[b]>0)
            {
                res+= min(mpp[b],i.second)*2;
            }
        }
        
        return res;
    }
};