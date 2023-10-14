class Solution {
public:
    long long ans=0;    //updates total cost
    long long dfs(vector<vector<int>> &v, int node, vector<int> &vis, int seats){
        vis[node]=true;
        //count of nodes coming to current node
        long long count=1;
        
        for(int i=0;i<v[node].size();i++){
            int curr=v[node][i];
            
            if(!vis[curr])
                count+=(dfs(v, curr, vis, seats));
        }
        //no of cars required
        long long x=count/seats;
        if(count%seats > 0)
            x++;    //if some people are left we have to increase the no of cars
        if(node!=0)
            ans+=x; //final ans to reach the goal state
        
        return count;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        //steps
        //har ek node pe kitne possible passenger h
        //evenly distribute passangers so that there is max utilization of cars
        //cost to reach goal state- capital city
        
        //create adjacency matrix
        if(roads.size()==0)
            return 0;
        int n=roads.size();
        ans=0;
        vector<vector<int>> v(n+1); //adjacency matrix
        
        for(int i=0;i<n;i++){
            int x=roads[i][0], y=roads[i][1];   //2d adj matix 
            v[x].push_back(y);
            v[y].push_back(x);
        }
        vector<int> vis(n+1, 0);
        dfs(v, 0, vis, seats);
        
        return ans;
    }
};