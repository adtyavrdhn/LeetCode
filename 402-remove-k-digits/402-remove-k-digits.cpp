class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        string res;
        
        int n = num.size();
        for(int i=0;i<n;i++)
        {
            
            while(res.size() && res.back() > num[i] && k > 0)
            {
                k--;
                res.pop_back();
            }
            
            if(num[i]!= '0' || res.size())
                res.push_back(num[i]);
        }
        
        while(res.size() && k > 0)
        {
            k--;
            res.pop_back();
        }
        
        if(res=="")
            return "0";
        
        return res;
    }
};