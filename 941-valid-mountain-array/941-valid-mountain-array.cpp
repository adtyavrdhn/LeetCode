class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        if(arr.size()<3)
            return false;
        
        int maxel=0;
        int count=0;
        for(int i=0; i< arr.size();i++)
        {
            if(arr[i]>arr[maxel])
                maxel = i;
        }
        
        if(maxel == arr.size()-1 || maxel == 0)
            return false;
        
        for(int i=maxel;i>=1;i--)
        {
            if(arr[i]-arr[i-1]<=0)
            {
                return false;
            }
        }
        
        for(int i=maxel;i<arr.size()-1;i++)
        {
            if(arr[i]-arr[i+1]<=0)
            {
                return false;
            }
               
        }
        
        return true;
    
    }
};