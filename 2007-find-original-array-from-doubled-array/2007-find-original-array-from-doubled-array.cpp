class Solution
{
    public:
        vector<int> findOriginalArray(vector<int> &arr)
        {
            int n = arr.size();
            
            if (n % 2 != 0)
            {
                return {};
            }
            
            map<int, int> mpp;

            for (int i = 0; i < n; i++)
            {
                mpp[arr[i]]++;
            }

            vector<int> res;

            for (auto i: mpp)
            {
               while(mpp[i.first]>0)
               {
                   mpp[i.first]--;
                   
                   int num = 2*i.first;
                   
                   if(mpp[num]<=0)
                   {
                       return {};
                   }
                   
                   mpp[num]--;
                   res.push_back(i.first);
               }
            }

            return res;
        }
};