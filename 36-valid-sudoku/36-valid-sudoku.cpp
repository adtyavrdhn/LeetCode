class Solution {
public:
     bool subGridValidation(vector<vector<char>> board,int r,int c) 
     { 
        unordered_map<char,bool> visited; 
        for(int i = r; i < r+3; i++) { 
            for(int j = c; j < c + 3; j++) { 
                 if(visited[board[i][j]] &&  board[i][j] !='.')
                    return false; 
                 
                 visited[board[i][j]] = true;
            }
        }
        return true; 
    }
    
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        //check row   
        for(int i = 0; i < 9; i++) {
            unordered_map<char,bool> visited; 
            
            for(int j = 0; j < 9; j++) {
                if(visited[board[i][j]] && board[i][j] !='.') {  
                    return false; 
                } 
                visited[board[i][j]] = true;   
            }
        }
        //check col  
        for(int i = 0; i < 9; i++) {
            unordered_map<char,bool> visited; 
            for(int j = 0; j < 9; j++) 
            {
                if(visited[board[j][i]] && board[j][i] !='.') { 
                    return false; 
                } 
                visited[board[j][i]] = true; 
            }
        }  
        //check sub grid 
        for(int i = 0; i<9; i+=3) {   
            for(int j = 0; j < 9; j+=3) 
            {
                 if(subGridValidation(board,i,j)==false) return false; 
            }
        }
        return true; 
    }
};