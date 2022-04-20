class Solution {
public:
    vector<vector<int>> adj;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        adj.resize(n);
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        
       return dfs(headID,informTime);
    }
    int dfs(int id, vector<int>& it)
    {
        int maxi = 0;
        
        
        for(auto i : adj[id])
        {
            maxi = max(maxi,dfs(i,it));
        }
        
        return it[id]+maxi;
    }
};