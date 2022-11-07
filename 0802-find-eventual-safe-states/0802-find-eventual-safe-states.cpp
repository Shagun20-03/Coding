class Solution {
    private:
    bool dfsCheck(int node, vector<vector<int>>& graph, vector<int> &vis, vector<int> &pathVis, vector<int> &check){
        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        //traverse for adjacent nodes
        for(auto it: graph[node]){
            if(!vis[it]){
                if(dfsCheck(it, graph, vis, pathVis, check)==true){
                    //not safe node as no cycle was found
                    check[node]=0;
                    return true;
                }
            }
            //if node is already visited and it has to be visited on the same path and no cycle was found
            else if(pathVis[it]==1){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>vis(V, 0);
        vector<int>pathVis(V, 0);
        vector<int>check(V, 0);
        vector<int> safeNodes;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsCheck(i, graph, vis, pathVis, check);
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]==1){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};