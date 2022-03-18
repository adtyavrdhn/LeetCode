class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0)
            return true;
    
        
        if( x < 0 || x%10 == 0)  return false;
        
        int reversed_int = 0;
        while(x > reversed_int)
        {
            int pop = x%10;
            
            reversed_int = (reversed_int*10) + pop;
            x/=10;
            
        }
        
        return x==reversed_int || x==reversed_int/10;
      
        
    }
};