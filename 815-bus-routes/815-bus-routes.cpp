class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int target) 
    {
        unordered_map<int,vector<int>> mpp;
        
        // stop -> set of buses
        
        for(int i=0;i<routes.size();i++)
        {
            for(int j=0;j<routes[i].size();j++)
            {
                mpp[routes[i][j]].push_back(i);
            }
        }
        
        unordered_map<int,bool> busvis;
        unordered_map<int,bool> stopvis;
        
        queue<pair<int,int>> q;
        
        // node,number of buses taken till now
        q.push({src,0});
        
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            if(node.first==target)
                return node.second;
            
            for(auto i : mpp[node.first])
            {
                // moving through the buses a particular stop has
                
                // if we find a bus that we haven't used
                if(!busvis[i])
                {
                    busvis[i]=true;
                    
                    // now let us traverse all the stops that we have for that bus
                    for(auto next : routes[i])
                    {
                         if(!stopvis[next])
                         {
                             stopvis[next] = true;
                             q.push({next,node.second+1});
                         }
                    }
                }
            }
        }
        
        return -1;
    }
};