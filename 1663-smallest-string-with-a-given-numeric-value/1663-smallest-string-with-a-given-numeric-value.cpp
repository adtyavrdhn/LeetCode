class Solution {
public:
   
    string getSmallestString(int n, int k) 
    {
        string res(n,'a');
        k = k - n;
        
        int count  = n - 1;
        string temp="";
        int c = 0;
        while(k!=0 && count>=0)
        {
            if(k>=26)
            {
                // cout<<"yes"<<endl;
                res[count]='z';
                k-=25;
            }
            else
            {
                res[count] = k + 'a';
                k=0;
            }
            
            count--;
        }
        
        
        return res;
    }
};