class Solution {
public:
    int countCollisions(string nums) 
    {
        int n = nums.size();
        int res=0;
        if(n<=1)
            return 0;
        
        int left=0,right=0;
        
            for(int i=0;i<n-1;i++)
            {
                left=i;
                right=i+1;
                
                if((nums[left] == 'R' && nums[right] =='L'))
                {
                    res+=2;
                    nums[left]=nums[right]='S'; 
                }
                
                else if(nums[left]=='S' && nums[right]=='L')
                {
                    res+=1;
                    nums[right]='S';
                    
                }
                else if(nums[left]=='R' && nums[right]=='S')
                {
                    res+=1;
                    nums[left]='S';
                   
                }
            }
        
        for(int i=n-1;i>=0;i--)
            {
                left=i;
                right=i+1;
                
                if((nums[left] == 'R' && nums[right] =='L'))
                {
                    res+=2;
                    nums[left]=nums[right]='S'; 
                }
                
                else if(nums[left]=='S' && nums[right]=='L')
                {
                    res+=1;
                    nums[right]='S';
                    
                }
                else if(nums[left]=='R' && nums[right]=='S')
                {
                    res+=1;
                    nums[left]='S';
                   
                }
            }
        
        
        // cout<<n;
        return res;
    }
};