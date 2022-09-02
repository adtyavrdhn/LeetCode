class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> res(n+1,0);
        
        for(int i=0;i<=n;i++)
        {
            res[i] = f(i);
        }
        
        return res;
    }
    int f(int n)
    {
        int count = 0;
        while(n!=0)
        {
            n = n&(n-1);
            count++;
            n = n>>1;
        }
        
        return count;
    }
};