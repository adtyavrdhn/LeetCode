class Solution {
public:
    vector<vector<int>> dp;
    int maximumScore(vector<int>& nums, vector<int>& mult) 
    {
        int n = nums.size();
        int m = mult.size();
        dp.resize(m+1, vector<int> (m+1,-1001));
        return f(nums,mult,0,0,n-1);
    }
    int f(vector<int>&nums, vector<int>&mult, int index, int i, int j)
    {
        if(index >= mult.size())
        {
            return 0;
        }
        
        if(dp[i][index]!=-1001)
            return dp[i][index];
        
        int first = nums[i]*mult[index] + f(nums,mult,index+1,i+1,j);
        
        int last = nums[j]*mult[index] + f(nums,mult,index+1,i,j-1);
        
        
        return dp[i][index] = max(first,last);
    }
};