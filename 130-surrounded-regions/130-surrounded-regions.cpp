class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    void f(vector<vector<char>>&board, int i, int j)
    {
        board[i][j]='#';
        
        for(int k=0;k<4;k++)
        {
            int nx = i + dir[k][0];
            int ny = j + dir[k][1];
            
            if(nx>=0 && ny>=0 && nx<board.size() && ny<board[nx].size() && board[nx][ny]=='O')
            {
                f(board,nx,ny);
            }
        }
        
    }
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0 || i == m-1 || j==n-1)
                {
                    if(board[i][j]=='O')
                       f(board,i,j);
                }
            }
        }
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                else if(board[i][j]=='#')
                {
                    board[i][j]='O';
                }
            }
        }
    }
};