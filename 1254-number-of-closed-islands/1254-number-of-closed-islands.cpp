class Solution {
    public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        int cnt=0;
        
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]==0 && dfs(row, col, n, m, grid, vis)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    bool dfs(int row, int col, int n, int m, vector<vector<int>>& grid, 
    vector<vector<bool>>& vis){
        if(row<0 || row>=n || col<0 || col>=m){
            return false;
        }
        if(grid[row][col]==1 || vis[row][col]){
            return true;
        }
        vis[row][col]=true;
        bool isClosed=true;
        int delrow[]={0, 1, 0, -1};
        int delcol[]={-1, 0, 1, 0};
        
        for(int i=0;i<4;i++){
           int nrow=row+delrow[i];
           int ncol=col+delcol[i];
           if(!dfs(nrow, ncol, n, m, grid, vis)){
               isClosed=false;
           }
       }
        return isClosed;
    }
};