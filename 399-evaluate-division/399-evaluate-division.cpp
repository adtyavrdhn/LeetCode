class Solution
{
    public:
    
    void dfs(string src,string des,unordered_map<string,vector<pair<string,double>>>&mpp,unordered_map<string,int> &vis,double &res,double temp)
    {
        // if we reach the destination
        if(vis.count(src))
            return;
        
        if(src == des)
        {
            res = temp;
            return;
        }
        vis[src]=1; // marking the source node as visited
        
        for(auto x : mpp[src])
        {
            dfs(x.first,des,mpp,vis,res,temp*x.second);
        }
        
        return;
    }
    
    vector<double> calcEquation(vector<vector < string>> &e, vector< double > &values, vector< vector< string>> &queries) 
    {
        vector<double> fres;
       unordered_map<string,vector<pair<string,double>>> mpp; // graph
        int n = e.size();
        
        // forming our graph
        for(int i=0;i<n;i++)
        {
            mpp[e[i][0]].push_back({e[i][1],values[i]}); // connection
            mpp[e[i][1]].push_back({e[i][0],1.0/values[i]}); // reverse connection
        }
        
        for(int i=0;i<queries.size();i++)
        {
            string src = queries[i][0];
            string des = queries[i][1];
            
            unordered_map<string,int> vis;
            double res = -1.0;
            double temp = 1.0;
            
            if(mpp.count(src))
            dfs(src,des,mpp,vis,res,temp);
            
            fres.push_back(res);
            
        }
        
        return fres;
    }
};