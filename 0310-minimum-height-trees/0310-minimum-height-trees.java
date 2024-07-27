class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        
        // If there's only one node, it's the root of the MHT by default
        if (n == 1) return List.of(0);

        // Initialize the adjacency list to store the graph
        List<List<Integer>> adj = new ArrayList<>();

        // Populate the adjacency list with empty lists for each node
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        // Array to keep track of the degree (number of connections) of each node
        int[] degree = new int[n];

        // Build the graph by populating the adjacency list and updating node degrees
        for (int i = 0; i < edges.length; i++) {
            adj.get(edges[i][0]).add(edges[i][1]);
            adj.get(edges[i][1]).add(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }

        // Initialize a queue to store leaf nodes (nodes with degree 1)
        Queue<Integer> q = new ArrayDeque<>();

        // Add all initial leaf nodes to the queue
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.offer(i);
        }

        // List to store the roots of the minimum height trees
        List<Integer> ans = new ArrayList<>();

        // Process nodes level by level until only the roots of MHTs are left
        while (!q.isEmpty()) {
            // Capture the current level of leaf nodes
            ans = new ArrayList<>(q);
            
            // Number of nodes to process at the current level
            int size = q.size();

            // Process each node in the current level
            for (int i = 0; i < size; i++) {
                int curr = q.poll();

                // Decrease the degree of each neighbor and add new leaf nodes to the queue
                for (int neighbor : adj.get(curr)) {
                    if (--degree[neighbor] == 1) {
                        q.offer(neighbor);
                    }
                }
            }
        }

        // Return the remaining nodes, which are the roots of the minimum height trees
        return ans;
    }
}
