class Solution {
public:
    int trap(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> pref(n,0);
        vector<int> suff(n,0);
        
        pref[0]=arr[0], suff[n-1]=arr[n-1];
        
        for(int i=1;i<n;i++)
        {
            pref[i] = max(pref[i-1],arr[i]);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            suff[i] = max(suff[i+1],arr[i]);
        }
        
        int res = 0;
        
        
        for(int i=0;i<n;i++)
        {
            res+= min(pref[i],suff[i])-arr[i];
        }
        
        return res;
    }
};