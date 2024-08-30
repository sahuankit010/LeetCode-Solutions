class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        // Adjacency list to store the graph: each node points to its neighbors with the corresponding success probability
        unordered_map<int, unordered_map<int, double>> adj;

        int c = 0; // Counter for accessing the succProb vector

        // Build the adjacency list for an undirected graph
        for(const auto &t: edges){
            adj[t[0]][t[1]] = succProb[c];   // Add edge from node t[0] to node t[1] with success probability succProb[c]
            adj[t[1]][t[0]] = succProb[c++]; // Since it's undirected, also add edge from node t[1] to node t[0]
        }

        // Map to store the maximum probability to reach each node
        unordered_map<int, double> prob;

        // Initialize all probabilities to 0.0 (unreachable)
        for(int i = 0; i < n; i++){
            prob[i] = 0.0;
        }

        // Priority queue (max-heap) to process nodes by the highest probability first
        // Stores pairs of {probability, node}
        priority_queue<pair<double, int>> pq;

        // Starting node has a probability of 1.0 to reach itself
        prob[start_node] = 1.0;

        // Push the start node into the priority queue
        pq.push({1.0, start_node});

        // Process the priority queue
        while(!pq.empty()){

            // Get the node with the highest probability from the queue
            double currPro = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            // If we reached the end node, return the probability
            if(currNode == end_node) return currPro;

            // Iterate through all neighbors of the current node
            for(auto &neighbor: adj[currNode]){
                // Calculate the new probability to reach the neighbor node
                double newPro = currPro * neighbor.second;

                // If the new probability is higher than the previously recorded probability, update it
                if(newPro > prob[neighbor.first]){
                    prob[neighbor.first]  = newPro;
                    pq.push({newPro, neighbor.first}); // Push the neighbor node with the updated probability into the queue
                }
            }
        }

        // If the end node is not reachable, return 0.0
        return 0.0;
    }
};
