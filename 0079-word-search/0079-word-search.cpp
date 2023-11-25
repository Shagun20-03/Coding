class Solution {
public:
    bool searchNext(vector<vector<char>>& board, string word, int row, int col, int ind, int m, int n){
        if(ind==word.length())
            return true;
        int dr[4]={-1, 0, 1, 0};
        int dc[4]={0, 1, 0, -1};
        
        if(row<0 || col<0 || row==m || col==n || board[row][col]!=word[ind] || board[row][col]=='.'){
            return false;
        }
        
        char ch=board[row][col];
        board[row][col]='.';
        
        bool top=searchNext(board, word, row-1, col, ind+1, m, n);
        bool right=searchNext(board, word, row, col+1, ind+1, m, n);
        bool left=searchNext(board, word, row, col-1, ind+1, m, n);
        bool bottom=searchNext(board, word, row+1, col, ind+1, m, n);
        
        board[row][col]=ch;  //undo change
        return top || right || left || bottom;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        int ind=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[ind]){
                    if(searchNext(board, word, i, j, ind, m, n))
                        return true;
                }
            }
        }
        return false;
    }
};