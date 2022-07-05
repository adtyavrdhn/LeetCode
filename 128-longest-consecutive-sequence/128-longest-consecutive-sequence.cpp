class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int res = 0;
        
        unordered_set<int> st(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            int num = nums[i]-1;
            
            if(st.find(num)==st.end())
            {
                int count = 0;
                
                num+= 1;
                
                while(st.find(num)!=st.end())
                {
                    num+= 1;
                    count++;
                }
                
                res = max(count,res);
            }
        }
        
        return res;
    }
};