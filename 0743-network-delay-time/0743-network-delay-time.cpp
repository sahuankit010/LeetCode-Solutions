class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // {node: {node, distance}}
        unordered_map<int, unordered_map<int, int>> adj;

        for(const auto &t: times){
            adj[t[0]][t[1]] = t[2];
        }
        // {node, distance}
        unordered_map<int, int> distances;

        for(int i=1; i<=n; i++){
            distances[i] = INT_MAX;
        }

        distances[k] = 0;

        // {distance, node} min heap
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

        pq.push({0, k});

        while(!pq.empty()){

            int currNode = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();

            if(currDist > distances[currNode]) continue;

            for(const auto &neighbor: adj[currNode]){
                int newDist = currDist + neighbor.second;

                if(newDist < distances[neighbor.first]){
                    distances[neighbor.first] = newDist;
                    pq.push({newDist, neighbor.first});
                }
            }
        }
        int ans = INT_MIN;
        for(const auto &[node, distance]: distances){
            if(distance == INT_MAX) return -1;
            ans = max(ans, distance);
        }

        return ans;
    }
};