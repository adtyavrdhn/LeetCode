class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        // sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        helper(candidates,target,res,temp,0);
        
        return res;
    }
    
    void helper(vector<int>& candidates, int target,vector<vector<int>>& res, vector<int>& temp,int index)
    {
     if(target==0)
     {
         res.push_back(temp);
         return;
     }
        
        for(int i=index;i<candidates.size();i++)
        {
            if(candidates[i] <= target)
            {
                temp.push_back(candidates[i]);
                helper(candidates,target-candidates[i],res,temp,i);
                temp.pop_back();
            }
        }
    }
};