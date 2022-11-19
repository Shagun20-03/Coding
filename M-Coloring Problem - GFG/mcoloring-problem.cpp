//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    private:
    //check whether the adjacent node has different color
    bool isSafe(int node, int color[], bool graph[101][101], int n, int curr_color){
        for(int k=0;k<n;k++) {
            //if it is not the node itself && graph[k][node]==1 means there is an edge & it is an
            //adjacent node && color of node is same as that of the color of adj node
          if(k!=node && graph[k][node]==1 && color[k]==curr_color){
              return false;
          }
        }
        return true;
    }
    bool solve(int node, int color[], int m , int n, bool graph[101][101]){
        //if all the nodes have been colored
        if(node==n)
        return true;
        
        //trying all the colors
        for(int i=1; i<=m; i++){
            //node, color array, i- color the node with that color
            if(isSafe(node, color, graph, n, i)){
                color[node]=i;
                if(solve(node+1, color, m, n, graph)==true)
                return true;
                color[node]=0;  //backtrack
            }
        }
        //if it is not possibel to color the grpah
        return false;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n]={0};
        if(solve(0, color, m, n, graph))
        return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends