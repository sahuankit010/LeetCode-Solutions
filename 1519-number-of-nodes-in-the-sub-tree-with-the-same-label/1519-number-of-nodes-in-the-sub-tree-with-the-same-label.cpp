class Solution {
public:
    vector<int> DFS(unordered_map<int, vector<int>> &adj,
                   int curr, int parent, vector<int> &res, string &labels){
        
        vector<int> myCount(26, 0);
        char myLabel = labels[curr];
        myCount[myLabel-'a'] = 1;
        for(int &v: adj[curr]){
            if(v==parent) continue;
            vector<int> child = DFS(adj, v, curr, res, labels);
            
            for(int i=0; i<26; i++){
                myCount[i]+= child[i];
            }
        }
        res[curr] = myCount[myLabel - 'a'];
        return myCount;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> adj;
        for(vector<int> &v: edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> res(n,0);
        DFS(adj, 0, -1, res, labels);
        return res;
    }
};