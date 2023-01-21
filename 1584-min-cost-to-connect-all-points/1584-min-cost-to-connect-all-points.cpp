class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();              // Total points.
        //vector<array<int, 3>> edges;        // All edges. Each point to every other point.
        vector<pair<int, pair<int, int>>> edges;
        for (int i=0; i<n-1; i++) {         // Point 1
            for (int j=i+1; j<n; j++) {     // Point 2
                                            
                int dist = abs(points[i][0]-points[j][0])
                           + abs(points[i][1]-points[j][1]); // Manhattan distance.
                edges.push_back({dist, {i, j}}); // Add the edge.
            }
        }
        DisjointSet ds(n);
        sort(edges.begin(), edges.end());
        int mstWt=0;
        for(auto it:edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(ds.findUPar(u)!=ds.findUPar(v)){
                mstWt+=wt;
                ds.unionBySize(u, v);
            }
        }
        return mstWt;
    }
};