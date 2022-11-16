class Solution {
    public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n){
        //base case
        if(col==n){
            ans.push_back(board);
            return;
        }
        //for every col we tried every row
        for(int row=0; row<n; row++) {
            if(leftRow[row]==0 && lowerDiagonal[row+col]==0 
               && upperDiagonal[(n-1)+(col-row)]==0) {
                
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[(n-1)+(col-row)]=1;
                
                solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
                
                //backtrack
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[(n-1)+(col-row)]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        //marking all the rows and cols of board as .
        string s(n, '.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        //we have queens only on left side till now
        vector<int>leftRow(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
        //0 is col
        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};