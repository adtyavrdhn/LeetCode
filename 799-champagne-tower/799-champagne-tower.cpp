class Solution {
public:
    double champagneTower(int poured, int qr, int qg) 
    {
    
        vector<vector<double>> a(102,vector<double>(102,0.0));
        a[0][0]=(double)poured;
        
        for(int i=0;i<=qr;i++)
        {
            for(int j=0;j<=i;j++)
            {
                double q = (a[i][j]-1.0)/2.0;
                
                if(q>0)
                {
                    a[i+1][j]+=q;
                    a[i+1][j+1]+=q;
                    a[i][j]=1;
                }
            }
        }
        
        
        return a[qr][qg];
    }
};