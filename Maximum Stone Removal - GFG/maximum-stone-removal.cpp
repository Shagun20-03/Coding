//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{
    vector<int> parent, size;
    public:
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            size[i]=1;
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findUPar(parent[node]);
    }
    void UnionBySize(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(size[ulp_u]<size[ulp_v]){
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
        else{
            size[ulp_v]+=size[ulp_u];
            parent[ulp_v]=ulp_u;
        }
    }
};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int maxRow=0, maxCol=0;
        for(auto it: stones){
            maxRow=max(maxRow, it[0]);
            maxCol=max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int, int>stoneNodes;
        for(auto it:stones){
            int nodeRow=it[0];
            int nodeCol=it[1]+maxRow+1; //to find the column using row
            ds.UnionBySize(nodeRow, nodeCol);   //connect them
            stoneNodes[nodeRow]=1;
            stoneNodes[nodeCol]=1;
        }
        //count connected component
        int cnt=0;
        for(auto it:stoneNodes){
            if(ds.findUPar(it.first)==it.first)
            cnt++;
        }
        return n-cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends