class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
            int n = nums.size();
             k=k%n;
        
           rv(nums,0,n-1);
           rv(nums,0,k-1);
           rv(nums,k,n-1);
           
            
    }
    
    void rv(vector<int>&nums, int start, int end)
    {
        while(start < end)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end]=temp;
            
            start++;
            end--;
        }
    }
};