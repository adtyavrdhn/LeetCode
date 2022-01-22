class Solution {
public:
  int catalan_Number(int n)
    {
        int catalan[n+1];
        catalan[0] = catalan[1] = 1;
        
        for(int i=2;i<=n;++i)
        {
            catalan[i] = 0;
            for(int j=0;j<i;++j)
                catalan[i] += catalan[j]*catalan[i-j-1];
        }
        return catalan[n];
    }
    
    int numTrees(int n) {
        return catalan_Number(n);
    }
};