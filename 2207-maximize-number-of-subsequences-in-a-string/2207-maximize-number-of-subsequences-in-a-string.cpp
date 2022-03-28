class Solution {
public:
    long long maximumSubsequenceCount(string t, string p) 
    {
        int n = t.size();
        long long forward = 0;
        long long backward=0;
        long long a=0;
        long long b=0;
        
        long long k=0;
        if(p[0]==p[1])
        {
            for(int i=0;i<n;i++)
            {
                if(p[0]==t[i]) k++;
            }
            
            long long res = (k + (k*(k-1))/2);
            return res;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(t[i]==p[1])
            {
               b++;
            }
            else if(t[i]==p[0] && b>0)
            {
               backward+=b;
            }
        }
        
       backward+=b;
        
        for(int i=0;i<n;i++)
        {
            if(t[i]==p[0])
            {
               a++;
            }
            else if(t[i]==p[1] && a>0)
            {
               forward+=a;
            }
        }
        
        forward+=a;
        
        return max(forward,backward);
        
    }
};