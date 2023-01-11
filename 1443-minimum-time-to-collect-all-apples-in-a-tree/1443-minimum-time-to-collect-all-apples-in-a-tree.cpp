class Solution {
public:
    int DFS(unordered_map<int,vector<int>> &adj, int curr, int parent, vector<bool> &hasApple){
        int time = 0;
        for(int &child: adj[curr]){
            if(child == parent) continue;
            int time_from_my_child = DFS(adj, child, curr, hasApple);
            if(time_from_my_child || hasApple[child])
                time += time_from_my_child + 2;
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adj;
        
        for(auto &vec: edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        
        return DFS(adj, 0, -1, hasApple);
    }
};