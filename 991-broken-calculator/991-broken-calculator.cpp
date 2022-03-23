class Solution {
public:
    int brokenCalc(int s, int target) 
    {
        return helper(s,target);
    }
    
    int helper(int s, int target)
    {
        if(s>=target)
            return s-target;
        
        if(target%2==0)
            return 1+ helper(s,target/2);
        
        return 1+helper(s,target+1);
    }
};