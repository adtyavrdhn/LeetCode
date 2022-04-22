class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});   
                }
                else
                    mat[i][j]=-1;
            }
        }
        
        int currlevel = 1;
        while(!q.empty())
        {
            // cout<<"here?";
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                // cout<<"here too";
                pair<int,int> point = q.front();
                q.pop();
                
                int x = point.first;
                int y = point.second;
                
                for(int j=0;j<4;j++)
                {
                    // cout<<"and here";
                    int nx = x + dir[j][0];
                    int ny = y + dir[j][1];
                    
                    if(nx>=0 && nx<m && ny>=0 && ny<n && mat[nx][ny]==-1)
                    {
                        mat[nx][ny]=currlevel;
                        q.push({nx,ny});
                    }
                }
                
                // Now we'll update the nodes in all the four directions with the level we are at 
            }
            
            currlevel++;
            // cout<<"made it";
        }
        
        return mat;
    }
};