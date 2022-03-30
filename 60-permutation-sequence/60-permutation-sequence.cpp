class Solution {
public:
    string getPermutation(int n, int k) 
    {
        string res=  "";
        int fact = 1;
        vector<int> nums;
        for(int i=1;i<n;i++)
        {
            fact *= i;
            nums.push_back(i);
        }
        
        nums.push_back(n);
        
        k-=1;
        
        while(true)
        {
            res += to_string(nums[k/fact]);
            nums.erase(nums.begin()+ k/fact);
            
            if(!nums.size()) break;
            
            k = k%fact;
            fact = fact / nums.size();
        }
        
        return res; 
    }
};