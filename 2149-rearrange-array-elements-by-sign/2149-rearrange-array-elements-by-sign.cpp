class Solution
{
    public:
        vector<int> rearrangeArray(vector<int> &nums)
        {
            int n = nums.size();
            
            vector<int> pos;
            vector<int> neg;

            for (int i = 0; i < n; i++)
            {
                if (nums[i] >= 0)
                    pos.push_back(nums[i]);
                else if (nums[i] < 0)
                    neg.push_back(nums[i]);
            }
            
            int p=0, ne = 0;
            
            vector<int> res;
            bool flag = false;
            while(p<pos.size() && ne < neg.size())
            {
                if(!flag)
                {
                    res.push_back(pos[p++]);
                    flag = true;
                }
                else
                {
                    res.push_back(neg[ne++]);
                    flag = false;
                }
            }
             
            if(p < pos.size())
            {
                res.push_back(pos[p++]);
            }
            if(ne<neg.size())
            {
                res.push_back(neg[ne++]);
            }
            
            
            return res;
        }
};