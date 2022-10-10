class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& arr, int target) 
    {
        vector<int> temp;
        f(arr,target,temp,0);
        
        return res;
    }
    void f(vector<int>&arr, int target, vector<int>&temp, int index)
    {
       if(target==0)
       {
           res.push_back(temp);
           return;
       }
        
        if(index>=arr.size())
            return;
        
        if(arr[index]<=target)
        {
            temp.push_back(arr[index]);
            f(arr,target-arr[index],temp,index);
            temp.pop_back();
        }
        
        f(arr,target,temp,index+1);
    }
};