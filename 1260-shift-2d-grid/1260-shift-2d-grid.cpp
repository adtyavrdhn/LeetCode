class Solution {
public:
    int m=0, n=0;
    void reverse(vector<vector<int>> &grid, int l, int r)
    {
        //treating the 2d matrix as a 1d array
        while(l<r)
        {
            int lr = l/n, lc = l%n; // row,col of first element
            int rr = r/n, rc = r%n; // row,col of last element
            
            swap(grid[lr][lc],grid[rr][rc]);
            
            l++;
            r--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
        m = grid.size(), n = grid[0].size();
        k = k%(m*n);
        if(k == 0) return grid;
        ////
// Could also have stored all the elements in a 1d array and then performed only the rotate array algorithm
        // Check Rotate Array Algorithm
        reverse(grid, 0, m*n-1);
        reverse(grid, 0, k-1);
        reverse(grid, k, m*n-1);
        return grid;
    }
};