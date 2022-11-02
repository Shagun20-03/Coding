//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, 
    vector<pair<int, int>>& vec, int row0, int col0){
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1, 0, +1, 0};
        int delcol[]={0, -1, 0, +1};
        
        vis[row][col]=1;
        //
        vec.push_back({row-row0, col-col0});
        
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 
            && grid[nrow][ncol]==1){
                vis[nrow][ncol]=1;
                dfs(nrow, ncol, vis, grid, vec, row0, col0);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int, int>>> st;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    //to store the list of 1 island at a time
                    vector<pair<int, int>>vec;
                    //2nd i, j for storing base row, col
                    dfs(i, j, vis, grid, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends