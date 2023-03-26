class Solution {
public:
    int longestCycle(vector<int>& edges) {
        //in directed graph we need an extra array to check if the node is visited twice that means there is a cycle
        vector<int>dist_node(edges.size(), 0);
        vector<bool>extra(edges.size(), false);
        vector<bool> visited(edges.size(), false);
        int ans=-1; //to store the length of the cycle
        
        for(int i=0;i<edges.size();i++){
            if(!visited[i]){
                dfs(i, dist_node, visited, edges, 0, ans, extra);
            }
        }
        return ans;
    }
    
    void dfs(int node, vector<int> &dist_node, vector<bool>&visited, vector<int> &edges, int distance, int &ans, vector<bool>& extra){
        if(node!=-1){
            if(!visited[node]){
                visited[node]=true;
                extra[node]=true;
                dist_node[node]=distance;
                dfs(edges[node], dist_node, visited, edges, distance+1, ans, extra);
            }
            else if(extra[node]){   //extra[node] is true means node is visted and there is cycle
                ans=max(ans, distance-dist_node[node]);
            }
            extra[node]=false; //marking node as false
        }
    }
};