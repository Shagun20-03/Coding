class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void UnionBySize(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)
            return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_v]+=size[ulp_u];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtraEdg=0;
        
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            //same component
            if(ds.findUPar(u)==ds.findUPar(v))
                cntExtraEdg++;
            else
                ds.UnionBySize(u, v);
        }
        int cntComp=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)
                cntComp++;
        }
        int ans=cntComp-1;
        if(cntExtraEdg>=ans){
            return ans;
        }
        else{
            return -1;
        }
    }
    
};