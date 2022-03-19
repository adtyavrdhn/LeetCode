class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> a;
        helper(candidates,0,target,ds,a);
        
        return a;
    }
    
   void helper(vector<int>& candidates,int index, int target,vector<int> &ds,vector<vector<int>> &a)
    {
       if(index == candidates.size())
           return;
       
       if(target==0)
         {
           a.push_back(ds);
           return;
         }
        
        if(candidates[index] <= target)
        {
            ds.push_back(candidates[index]);
            helper(candidates,index,target-candidates[index],ds,a);
            ds.pop_back();
        }
            helper(candidates,index+1,target,ds,a);
        
    }
};