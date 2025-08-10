class Solution {
public:

    bool isAllowed(vector<vector<char>>& board,int row, int col, char dig){
        for(int i=0; i<9; i++){
            if(board[row][i] == dig){
                return false;
            }
        }
        for(int i=0; i<9; i++){
            if(board[i][col] == dig){
                return false;
            }
        }
        int stRow = (row/3)*3,  stCol = (col/3)*3;
        for(int i=stRow; i<=stRow+2; i++){
            for(int j=stCol; j<=stCol+2; j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }
        return true;
    }

    bool sudokuSolver(vector<vector<char>>& board,int row, int col){
        if(row == 9){
            return true;
        }
        int nextRow = row, nextCol = col+1;
        if(col == 8){
            nextRow = row+1;
            nextCol = 0;
        }
        if(board[row][col] != '.'){
            return sudokuSolver(board, nextRow, nextCol);
        }
        for(char dig = '1'; dig <= '9'; dig++){
            if(isAllowed(board, row, col, dig)){
                board[row][col] = dig;
                if(sudokuSolver(board, nextRow, nextCol)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
     
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board, 0,0);
    }
};