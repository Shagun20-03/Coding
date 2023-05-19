class Solution {
    //colors a component using bfs
    private:
    bool check(int start, int V, vector<vector<int>>& graph, int color[]){
        queue<int> q;
        q.push(start);
        //starting the color of node with 0
        color[start]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto it: graph[node]) {
                if(color[it]==-1){
                    //color the adj node with opposite color of current node
                    color[it]=!color[node];
                    q.push(it);
                }
                //already colored with the same color of the current node
                else if(color[it]==color[node]) {
                    return false;
                }
            }
        }
        //if we can traverse and color through the end of that component it is bipartite
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        int color[V];
        for(int i=0;i<V;i++) {
            color[i]=-1;
        }
        //checking for all components
        for(int i=0;i<V;i++) {
            if(color[i]==-1) {
                if(check(i, V, graph, color)==false) {
                    return false;
                }
            }
        }
        //if we can traverse and color through the end of the graph it is bipartite
        return true;
    }
};