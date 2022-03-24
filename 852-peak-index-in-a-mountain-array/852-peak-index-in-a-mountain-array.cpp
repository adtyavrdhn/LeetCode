class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int n = size(arr);
        return bs(arr,0,n-1);
    }
    
    int bs(vector<int>& arr, int left, int right)
    {
        if(left==right)
            return left;
        
        int mid = (left+right)/2;
        
        if(arr[mid]>arr[mid+1])
            return bs(arr,left,mid);
        
        return bs(arr,mid+1,right);
    }
};