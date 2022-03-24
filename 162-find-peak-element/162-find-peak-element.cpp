class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int n = size(nums);
        return bs(nums,0,n-1);
    }
    
    int bs(vector<int> &nums, int left, int right)
    {
        if(left==right)
        return left;
        
        
        int mid = (left+right)/2;
        if(nums[mid]>nums[mid+1])
            return bs(nums,left,mid);
        
        return bs(nums,mid+1,right);
    }
};