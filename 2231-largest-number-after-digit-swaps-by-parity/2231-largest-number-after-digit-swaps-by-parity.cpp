class Solution {
public:
    int largestInteger(int num) 
    {
        string s = to_string(num);
        int n = s.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>i;j--)
            {
                int n1 = s[i]-'0';
                int n2 = s[j]-'0';
                
                if(n2 > n1)
                {
                    if(n1%2==0 && n2%2==0)
                    {
                        swap(s[i],s[j]);
                    }
                    else if(n1%2!=0 && n2%2!=0)
                    {
                        swap(s[i],s[j]);
                    }
                }
            }
        }
        
        return stoi(s);
    }
};