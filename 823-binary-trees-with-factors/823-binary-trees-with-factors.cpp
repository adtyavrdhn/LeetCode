class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        int n = arr.size();
        map<int,long long int> mpp;
        
       long long int mod = 1e9 + 7;
        
        sort(arr.begin(),arr.end());
        
        for(auto i : arr)
        {
            mpp[i]++;
        }
        
        for(int i=1;i<n;i++)
        {
            long long int count = 0;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    auto it = mpp.find(arr[i]/arr[j]);
                    
                    if(it!=mpp.end())
                    {
                        count += (it->second)*(mpp[arr[j]]);
                    }
                }
            }
            
            mpp[arr[i]]+= count;
        }
        
        long long int res = 0;
        
        for(auto i : mpp)
        {
            res+= i.second;
        }
        
        return res%mod;
    }
};