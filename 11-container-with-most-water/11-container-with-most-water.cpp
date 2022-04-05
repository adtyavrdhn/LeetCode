class Solution {
public:
    int maxArea(vector<int>& h) 
    {
        int res = INT_MIN;
        int n = size(h);
        int left = 0;
        int right = n-1;
        
        while(left < right)
        {
            int water = (right-left)*min(h[right],h[left]);
            
            res = max(water,res);
            
            if(h[left]<h[right])
            {
                left++;
            }
            else
                right--;
        }
        
        return res;
    }
};