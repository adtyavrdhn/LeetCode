class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
      string ans="";
        
        for(int i=0;i<n;i++)
        {
            
            while(ans.size() && ans.back()>num[i] && k>0)
            {
                ans.pop_back();
                k--;
            }
            
            if(ans.size() || num[i]!='0')
                 ans.push_back(num[i]);
        }
        
        while(k-- && ans.size())
            ans.pop_back();
        
        if(ans=="")
            return "0";
        
        return ans;
    }
};