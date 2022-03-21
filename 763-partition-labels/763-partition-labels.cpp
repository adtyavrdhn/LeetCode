class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        vector<int> res;
        vector<int> mpp(26,0);
        int n = size(s);
        for(int i=0;i<n;i++)
        {
            mpp[s[i]-'a']=i;
        }
        
        
        int last_index;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            last_index=max(last_index,mpp[s[i]-'a']);
            sum++;
            if(i==last_index)
            {
                res.push_back(sum);
                sum=0;
            }
        }
        
        return res;
    }
};