class Solution {
public:
     vector<vector<string>> res;
    int totalNQueens(int n) {
        // return empty if n <= 0
        if(n <= 0) return {{}};
        
        vector<string> board(n,string(n,'.'));
        
        
        dfs(board,0);
        
        
        return res.size();
    }
     void dfs(vector<string> &board, int row)
    {
        // exit condition
        if(row == board.size())
        {
            res.push_back(board);
            return;
        }
        
        
        // iterate every possible position
        
        for(int i=0;i<board.size();++i)
        {
            if(is_valid(board,row,i))
            {
                // make decision
                board[row][i] = 'Q';
                
                
                // next iteration
                dfs(board,row+1);
                
                
                // back-tracking
                board[row][i] = '.';
            }
        }
    }
    
    bool is_valid(vector<string> &board, int row, int col)
    {
        // check col
        for(int i=row;i>=0;--i)
            if(board[i][col] == 'Q') return false;
        
        // check left diagonal
        for(int i=row,j=col;i>=0 && j>=0;--i,--j)
            if(board[i][j] == 'Q') return false;
        
        
        //check right diagonal
        for(int i=row,j=col;i>=0 && j<board.size();--i,++j)
            if(board[i][j] == 'Q') return false;
        
        
        return true;
    }
};