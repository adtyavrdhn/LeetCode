class Solution {
public:
    int minDeletion(vector<int>& nums) 
    {
        int n = size(nums);
        int count = 0;
        
        if(n==1)return 1; // if there is only one digit, delete it and make the array empty
        if(n==0) return 0; // empty array is beautiful
        
        
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                
                if((i-count)%2==0 || (i==n-2)) // (i-count) makes sure we are always looking at indices in the context of elements that have been deleted, basically left shifting of elements. Dry run it and you'll notice it
                {
                    count++; // counts elements being deleted
                }
            }
        }
        
        
        if((n-count)%2!=0) // odd
        {
            return count+1; // we'll need to delete one more element to make it even
        }
        
        return count;
    }
};