class Solution {
public:
    int maxArea(int h, int w, vector<int>& hcuts, vector<int>& vcuts) 
    {
        sort(hcuts.begin(),hcuts.end());
        sort(vcuts.begin(),vcuts.end());
        
        int MOD = 1e9 + 7;
        
         int maxh = max(hcuts[0],h-hcuts[hcuts.size()-1]);
         int maxv = max(vcuts[0],w-vcuts[vcuts.size()-1]);
           
        for(int i=1;i<hcuts.size();i++)
        {
            int cut = hcuts[i]-hcuts[i-1];
            
            maxh = max(cut,maxh);
        }
        
        for(int i=1;i<vcuts.size();i++)
        {
            int cut = vcuts[i]-vcuts[i-1];
            maxv = max(maxv,cut);
        }
        
        return ((long long)maxh%MOD*maxv%MOD)%MOD;
    }
};