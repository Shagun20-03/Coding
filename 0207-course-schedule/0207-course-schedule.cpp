class Solution {
    // private:
    // bool detect(int src, vector<vector<int>> prerequisites, int vis[]){
//         vis[src]=1;
//         queue<pair<int, int>> q;
//         //{curr_node, parent node}
//         q.push({src, -1});
//         while(!q.empty())
//         {
//             int node=q.front().first;
//             int parent=q.front().second;
//             q.pop();
            
//             for(auto adjacentnode: prerequisites[node]){
//                 if(!vis[adjacentnode]){
//                     vis[adjacentnode]=1;
//                     q.push({adjacentnode, node});
//                 }
//                 else if(parent!=adjacentnode)
//                     return true;
//             }
//         }
//         return false;
//     }
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         int vis[numCourses]={0};
// //         vector<int> adj(numCourses);
        
// //         for(int i=0;i<prerequisites.size();i++){
// //             adj
// //         }
        
//         for(int i=0;i<numCourses;i++)
//         {
//             if(!vis[i])
//             {
//                 if(detect(i, prerequisites, vis))
//                     return true;
//             }
//         }
//         return false;
    public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        queue<int> zeroDegree;
        for(int i = 0; i<prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        
        for(int i = 0; i<degree.size(); i++){
            if(degree[i] == 0){
                zeroDegree.push(i);
                numCourses--;
            }
        }
        
        while(!zeroDegree.empty()){
            int node = zeroDegree.front();
            zeroDegree.pop();
            for(int i = 0; i<graph[node].size(); i++){
                int connectedNode = graph[node][i];
                degree[connectedNode]--;
                if(degree[connectedNode] == 0){
                    zeroDegree.push(connectedNode);
                    numCourses--;
                }
            }
        }
        
        return numCourses == 0;
    }
};