class Solution {
public:
     vector<vector<int>> dirs ={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,1},{1,-1},{1,0}};
    void gameOfLife(vector<vector<int>>& board) 
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> nboard(m,vector<int> (n));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int nei = 0;
                
                for(auto d : dirs)
                {
                    int r = i + d[0];
                    int c = j + d[1];
                    
                    if(r<0 || c<0 || r>=m || c>=n) continue;
                    
                    nei+= board[r][c];
                }
                
                if(board[i][j]==1 && nei<2)
                {
                    nboard[i][j]=0;
                }
                else if(board[i][j]==1 && (nei==2 || nei==3))
                {
                    nboard[i][j]=1;
                }
                else if(board[i][j]==1 && nei>3)
                {
                    nboard[i][j]=0;
                }
                else if(board[i][j]==0 && nei==3)
                {
                    nboard[i][j]=1;
                }
            }
        }
        
        
        board=nboard;
    }
};