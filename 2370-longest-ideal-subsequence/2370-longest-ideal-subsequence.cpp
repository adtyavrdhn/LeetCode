class Solution {
public:
     int dp[100005][28];
    
    int func(string &str , int k , int n , int i ,  char last_char )
    {
        if(i>=n)
        {
            return 0;
        }
        
        int idx=26;
        
        if(last_char!='#')
        {
            idx=last_char-'a';
        }
        
        if(dp[i][idx]!=-1)
        {
            return dp[i][idx];
        }
        
        int res=0;
        
        int v=abs(last_char-str[i]);
        
        if(last_char=='#' || v<=k)
        {
             res = 1 + func(str , k , n , i+1 , str[i]);
        }
         
        res=max(res , func(str , k , n , i+1 , last_char));
        
        return dp[i][idx]=res;
        
        
    }
    int longestIdealString(string s, int k) {
        
        int n=s.size();
        
        memset(dp , -1 , sizeof(dp));
        
        string str= s;
        
        n=str.size();
        
        char ch='#';
        
        int ans =  func(str , k , n , 0 , ch);
        
        return ans;
        
        
    }
};