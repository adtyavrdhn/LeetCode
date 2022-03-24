class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
        int n = size(mat);
        int top = 0;
        int bottom = n-1;
        
        while(top<=bottom)
        {
            int midrow = top + (bottom-top)/2;
            
            int rowmax = maxinarow(mat[midrow]);
            if(midrow==0)
            {
                if(mat[midrow][rowmax] > mat[midrow+1][rowmax])
                    return {midrow,rowmax};
            }
            
            if(midrow==n-1)
            {
                if(mat[midrow][rowmax] > mat[midrow-1][rowmax])
                    return {midrow,rowmax};
            }
            
            if((mat[midrow][rowmax] > mat[midrow+1][rowmax])
               &&(mat[midrow][rowmax] > mat[midrow-1][rowmax]))
                return {midrow,rowmax};
            
            if(mat[midrow][rowmax]<mat[midrow+1][rowmax])
                top = midrow+1;
            else
                bottom = midrow-1;
        }
        
        return {-1,-1};
    }
    
    int maxinarow(vector<int>& arr)
    {
        int maxi = 0;
        for(int i=0;i<size(arr);i++)
        {
            if(arr[i]>arr[maxi])
                maxi = i;
        }
        
        return maxi;
    }
};