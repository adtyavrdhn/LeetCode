class Solution {
public:
     int floorMod(int x, int y) {
        return ((x % y) + y) % y;
    }
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> arr (n,vector<int> (n,0));
        
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        
        
        int count = 1;
        int i=0,j=0;
        int d = 0;
        while(count<=n*n)
        {
           arr[i][j]=count++;
           int r = floorMod(i+dir[d][0],n);
           int c = floorMod(j+dir[d][1],n);
            
            if(arr[r][c]!=0)
                d=(d+1)%4; // 4 directions
            
            i+=dir[d][0];
            j+=dir[d][1];
            
        }
        
       return arr;
    }
};