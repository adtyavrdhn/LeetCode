class Solution {
public:
    bool isHappy(int n) 
    {
        int fast = n, slow = n;
       
        do
        {
          slow=getnext(slow);
            fast=getnext(getnext(fast));
        } while(slow != fast);
        
        
        return slow==1;
    }
    
    int getnext(int n)
    {
        int pop = 0;
        int newn=0;
        while(n!=0)
        {
            pop = n%10;
            pop=pop*pop;
            newn+=pop;
            n/=10;
        }
        
        
        return newn;
    }
};