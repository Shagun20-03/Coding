class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //return true if there is no cycle as if there will be a cycle we may not take the course according to the question so we will check for topo sort if topo sort is there for all n it means there is no cycle
        //so we are coding for detect a cycle for directed graph using bfs
        vector<vector<int>> adj(numCourses);
        vector<int>indegree(numCourses, 0);
        int cnt=0;
        
        for(auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<indegree.size();i++) {
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            //topo.push_back(node);
            
            //node is in the topo sort so remove it from indegree
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return cnt==numCourses;
        // if(cnt == numCourses)
        //     return true;
        // else 
        //     return false;
    }
};