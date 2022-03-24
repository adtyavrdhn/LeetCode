class Solution {
public:
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9,10,11};
    int max_score=INT_MIN;
    
    vector<int> maximumBobPoints(int n, vector<int>& arr) 
    {
        vector<int> res(12,0);
        vector<int> temp(12,0);
        helper(n,arr,temp,11,0,res);
        
        return res;
    }
    
    void helper(int n,vector<int>& arr,vector<int>& temp, int index, int sum,vector<int> &res)
    {
        if(n<=0 || index==-1)
        {
            if(sum > max_score)
            {
                max_score = sum;
                
                if(n>0)
                {
                    temp[0]+=n;
                }
                res = temp;
            }
            
            return;
        }
        
        int req_arrows = arr[index] + 1;
        
        if(n >= req_arrows)
        {
            temp[index]=req_arrows;
            // cout<<nums[index]<<" ";
            helper(n-req_arrows,arr,temp,index-1,sum+nums[index],res);
            temp[index]=0;
        }
        
        helper(n,arr,temp,index-1,sum,res);
        return;
    }
};