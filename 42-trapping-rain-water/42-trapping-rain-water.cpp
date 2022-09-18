class Solution {
public:
    int trap(vector<int>& arr) 
    {
        int left = 0,right=0;
        
        int n = arr.size();
        
        int i=0,j=n-1;
        
        int res = 0;
        
        while(i<j)
        {
            if(arr[i]<=arr[j])
            {
                left = max(left,arr[i]);
                res+= left-arr[i];
                i++;
            }
            else
            {
                right = max(right,arr[j]);
                res+= right-arr[j];
                j--;
            }
        }
        
        return res;
    }
};