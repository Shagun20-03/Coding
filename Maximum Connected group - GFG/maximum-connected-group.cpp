//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findUPar(int node){
        if(parent[node]==node)
            return node;
        return parent[node]=findUPar(parent[node]);
    }
    
    void UnionBySize(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
    private:
    bool isValid(int newr, int newc, int n){
        return newr>=0 && newc>=0 && newr<n && newc<n;
    }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        DisjointSet ds(n*n);
        
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                int dr[]={-1, 0, +1, 0};
                int dc[]={0, -1, 0, +1};
                for(int ind=0;ind<4;ind++){
                    int newr=row+dr[ind];
                    int newc=col+dr[col];
                    if(isValid(newr, newc, n) && grid[newr][newc]==1){  
                        int nodeNo=n*row+col;   //n is the n of col
                        int adjNodeNo=n*newr+newc;
                        ds.UnionBySize(nodeNo, adjNodeNo);  //connect them
                    }       
                }
            }
        }
        //step 2 convert all 0s to 1s
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int dr[]={-1, 0, +1, 0};
                int dc[]={0, -1, 0, +1};
                set<int> components;
                for(int ind=0;ind<4;ind++){
                    int newr=row+dr[ind];
                    int newc=col+dc[ind];
                    if(isValid(newr, newc, n)){
                        if(grid[newr][newc]==1){ //if it is 1 then only we can connect
                            components.insert(ds.findUPar(newr*n+newc));
                        }
                    }
                }
                int sizeTotal=0;    //current total size of component
                for(auto it: components) {
                    sizeTotal+=ds.size[it];
                }
                mx=max(mx, sizeTotal+1);    //include compponents of converting 0 to 1
            }
        }
        for(int cellNo=0;cellNo<n*n;cellNo++){
            mx=max(mx, ds.size[ds.findUPar(cellNo)]);
        }
        return mx;
 
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends
