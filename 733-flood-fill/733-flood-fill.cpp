class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>> q;
        
        
        pair<int,int> temp = make_pair(sr,sc);
        int oldc = image[sr][sc];
        if(oldc == newColor)
            return image;
        
        q.push(temp);
        
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            
            int r = temp.first;
            int c = temp.second;
            
            image[r][c]=newColor;
            
            for(auto &d: dir)
            {
                int nr = r + d[0];
                int nc = c + d[1];
                
                
                if(nc>=0 && nc<n && nr>=0 && nr<m && image[nr][nc]==oldc)
                {
                    temp = make_pair(nr,nc);
                    q.push(temp);
                }
                
            }
            
        }
        
        return image;
    }
};