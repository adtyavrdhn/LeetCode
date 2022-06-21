class Solution {
public:
    bool feasible(vector<int>& h, int bricks, int ladders, int mid)
    {
        vector<int> arr;
        
        for(int i=1;i<=mid;i++)
        {
            if(h[i] > h[i-1])
              arr.push_back(h[i]-h[i-1]);
        }
        
        sort(arr.begin(),arr.end(),greater<int>());
    
        int sz = arr.size();
        
        for(int i=ladders;i<sz;i++)
        {
            if(arr[i]>bricks) return false;
            
            bricks-=arr[i];
        }
        
        return true;  
    }
    int furthestBuilding(vector<int>& h, int bricks, int ladders) 
    {
        int low = 0;
        int high = h.size()-1;
        int res = -1;
        
        while(low < high)
        {
            int mid = (low+high+1)/2;
            
            if(feasible(h,bricks,ladders,mid))
            {
                low = mid;
            }
            else
                high = mid - 1;
        }
        
        return low;
        
    }
};