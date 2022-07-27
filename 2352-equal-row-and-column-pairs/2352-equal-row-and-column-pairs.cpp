class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        unordered_map<string,int> rows;
        unordered_map<string,int> cols;
        
        for(int i=0;i<grid.size();i++)
        {
            string row = "";
            for(int j=0;j<grid.size();j++)
            {
                row = row + to_string(grid[i][j]) + '.';
            }
            
            rows[row]++;
        }
        
         for(int i=0;i<grid.size();i++)
        {
            string col = "";
            for(int j=0;j<grid.size();j++)
            {
                col= col + to_string(grid[j][i]) + '.';
            }
            
            cols[col]++;
        }
        
        int res = 0;
    
        
        for(auto i : rows)
        {
            if(cols.find(i.first)!=cols.end())
            {
                // cout<<i.first<<" "<<i.second<<" "<<cols[i.first]<<endl;
                res = res + i.second*(cols[i.first]);
            }
        }
        
        return res;
        
    }
};