class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {
        int n = grumpy.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)
                sum+= customers[i];
        }
        
        int l=0,r=0,res=0;
        
        while(r<n)
        {
            if(grumpy[r]==1)
                sum+= customers[r];
            
            if(r-l+1<minutes)
                r++;
            
            else if(r-l+1 == minutes)
            {
                res = max(sum,res);
                
                if(grumpy[l]==1)
                    sum-= customers[l];
                l++,r++;
            }
        }
        
        return res;
    }
};