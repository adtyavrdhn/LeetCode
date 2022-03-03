class Solution {
public:
    int maxArea(vector<int>& height) 
    {
     int res=0;
        
        
     int left = 0;
     int right = height.size()-1;
        
     int water=0;
        int h=0;
     while(left < right)
     {
          h = min(height[right],height[left]);
         water= h * (right-left);
         res=max(res,water);
        
         if(height[right]<=height[left])
             right--;
         else
             left++;
         
     }
        return res;
    }
};