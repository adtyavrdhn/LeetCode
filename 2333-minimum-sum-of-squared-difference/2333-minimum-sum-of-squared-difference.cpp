class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) 
    {
        int n = nums1.size();
        
        int maxdiff = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            maxdiff = max(abs(nums1[i]-nums2[i]),maxdiff);
        }
        
        vector<int> freq(maxdiff+1,0);
        
        for(int i=0;i<n;i++)
        {
            int diff = abs(nums1[i]-nums2[i]);
            freq[diff]++;
        }
        
        int k = k1 + k2;
        
        for(int i=maxdiff;i>0;i--)
        {
            if(freq[i]==0)
                continue;
            
            if(k>= freq[i])
            {
                freq[i-1]+= freq[i];
                k-=freq[i];
                freq[i]=0;
            }
            else
            {
                freq[i-1]+= k;
                freq[i]=freq[i]-k;
                k=0;
                break;
            }
        }
        
        long long res = 0;
        for (long long j = 1; j <= maxdiff; j ++) 
            if (freq[j] > 0) res += j*j*freq[j];
        
        return res;
        
        // https://www.youtube.com/results?search_query=+Minimum+Sum+of+Squared+Difference
        
    }
};