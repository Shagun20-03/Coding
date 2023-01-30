//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    vector<int> parent, size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUPar(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findUPar(parent[node]);
    }
    void UnionBySize(int u, int v) {
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
    bool isValid(int adjr, int adjc, int n, int m){
        return adjr>=0 && adjr<n && adjc>=0 && adjc<m;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis, 0, sizeof(vis));
        int cnt=0;
        vector<int> ans;
        
        for(auto it:operators) {
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt); //add cnt to ans no need to increase cnt
                continue;
            }
            vis[row][col]=1;
            cnt++;  //when a node is visited increase cnt by 1
            int dr[]={-1, 0, +1, 0};
            int dc[]={0, 1, 0, -1};
            
            for(int ind=0; ind<4; ind++) {
                int adjr=row+dr[ind];
                int adjc=col+dc[ind];
                if(isValid(adjr, adjc, n, m)) {      //checking if we are inside the matrix
                    if(vis[adjr][adjc]==1) { 
                        int nodeNo=row*m+col;
                        int adjNodeNo=adjr*m+adjc;
                        if(ds.findUPar(nodeNo)!=ds.findUPar(adjNodeNo)){
                            cnt--; //decrease the count if they dont have same parent as we have already increased the count
                            ds.UnionBySize(nodeNo, adjNodeNo);  //connect the adjacent node with the current node
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends