class Solution {
public:
    
    bool dfs(vector<vector<int>> &adj, int curr, int destination, vector<bool> &visited){
        if(curr == destination) return true;
        
        visited[curr] = true;
        
        for(int a: adj[curr]){
            if(!visited[a])
                if(dfs(adj, a, destination, visited)) return true; 
        }
        
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adj(n);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        
        return dfs(adj, source, destination, visited);
    }
};