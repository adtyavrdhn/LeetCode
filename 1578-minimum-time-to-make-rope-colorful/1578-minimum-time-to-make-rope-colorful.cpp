class Solution {
public:
    int minCost(string colors, vector<int>& arr) 
    {
        int res = 0, maxi = 0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(i>0 && colors[i]!=colors[i-1])
            {
                maxi = 0;
            }
            
            res+= min(maxi,arr[i]);
            maxi = max(maxi,arr[i]);
        }
        
        return res;
    }
};