class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board) {
        //traversing the whole board
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                //if any cell is empty
                if(board[i][j]=='.') {
                    for(char c='1'; c<='9'; c++) {
                        if(isValid(board, i, j, c)) {
                            board[i][j]=c;
                            
                            //if a character can be placed at that place return true else leave it empty
                            if(solve(board)==true)
                                return true;
                            else
                                board[i][j]='.';
                        }
                    }
                    //if there no empty cell
                    return false;
                }
            }
        }
        //if all the cells are filled
        return true;
    }
    //checking the rules for each grid in that row, col and its own grid
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        //traversing the whole grid
        for(int i=0; i<9; i++) {
            //checking in a particular column: row change col same
            if(board[i][col]==c)
                return false;
            //checking in a perticular row: column change row same
            if(board[row][i]==c)
                return false;
            //from row and col we are starting that grid traversal
            //dividing by 3 bcoz it has 3 row and  col
            //i/3 will be change in row and i%3 will be change in col 
            //if that already has that character wil return false
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
                return false;
        }
        return true;
    }
};