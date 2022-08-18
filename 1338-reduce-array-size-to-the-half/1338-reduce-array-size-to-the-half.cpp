class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        unordered_map<int,int> mpp;
        int n = arr.size();
        
        
        for(int i=0;i<n;i++)
        {
            mpp[arr[i]]++;
        }
        
        priority_queue<pair<int,int>> pq;
        
        for(auto i : mpp)
        {
            pq.push({i.second,i.first});
        }
        
        int count = 0;
        int res = 0;
        
        while(!pq.empty())
        {
            auto k = pq.top();
            pq.pop();
            
            count+= k.first;
            res++;
            
            if(count>=n/2)
            {
                return res;
            }
        }
        
        return res;
    }
};