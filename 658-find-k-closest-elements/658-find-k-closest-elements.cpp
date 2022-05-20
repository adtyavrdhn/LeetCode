class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    { 
        int n = arr.size();
        int low = 0;
        int high = n-1;
        
        int index = -1;
        
        while(low < high)
        {
            int mid = (low+high)/2;
                 
            if(arr[mid] < x)
                low = mid + 1;
            
            else
                high = mid;
        }
        
        index = high;
        
        
        int l_index = min(n-1,index+k);
        int f_index = max(0,index-k);
        
        
        while (l_index  - f_index >= k) {
            if (x - arr[f_index] <= arr[l_index ] - x) --l_index ;
            else ++f_index;
        }
        
        
        vector<int> res;
        
        for(int i=f_index;i<=l_index;i++)
        {
            res.push_back(arr[i]);
        }
        
        return res;
        
    }
};