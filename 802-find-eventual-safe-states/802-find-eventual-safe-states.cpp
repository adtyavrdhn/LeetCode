class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
      int n = graph.size();
        
        vector<int> indegree(n, 0), al[n];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < graph[i].size(); j++){
                al[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        
        vector<int> res;
        
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int sz = q.size();
            bool flag = false;
            while(sz--){
                
                int curr = q.front();
                q.pop();
                
                res.push_back(curr);
                
                for(int i = 0; i < al[curr].size(); i++){
                    int child = al[curr][i];
                    indegree[child]--;
                    if(indegree[child] == 0){
                        q.push(child);
                        flag = true;
                    }
                }
            }
            if(!flag) break;
        }
        sort(res.begin(),res.end());
        return res;
    }
};