class Solution {
public:
    int mod = 1e9+7;
    
     int countHousePlacements(int N) {
        // if N = 1 total number of ways are 4 = 2*2
        // if N = 2 total number of ways are 9 = 3*3
        // if N = 3 total number of ways are 25 = 5*5
        // this forms a fibonacci series -> 2, 3, 5, 8, ... => current number = sum of previous two numbers
        
        if(N==1) return 2*2; 
	    if(N==2) return 3*3;
        
	    long long  first=2;
	    long long  second=3;
	    long long  third;
        
	    for(int i=2 ; i<N ; i++)
	    {
	        third = ((first % mod) + (second % mod)) % mod;
	        first = second % mod;
	        second = third % mod;
	    }
	    long long int ans= ((third % mod) * (third % mod))%mod;
	    return ans;
    }
};