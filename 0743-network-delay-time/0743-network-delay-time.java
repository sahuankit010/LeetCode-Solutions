import java.util.*;

class Solution {

    public int networkDelayTime(int[][] times, int n, int k) {
        // Create adjacency list representation of the graph
        Map<Integer, Map<Integer, Integer>> adjList = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            adjList.put(i, new HashMap<>());
        }
        for (int[] arr : times) {
            adjList.get(arr[0]).put(arr[1], arr[2]);
        }

        // Initialize distances map with infinity for all nodes except the starting node k
        Map<Integer, Integer> distances = new HashMap<>();

        for (int i=1; i<=n; i++){
            distances.put(i, Integer.MAX_VALUE);
        }
        
        distances.put(k, 0);

        // Priority queue to keep track of nodes to process, starting with node k
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>(Map.Entry.comparingByValue());
        pq.offer(Map.entry(k, 0));

        // Main loop to process nodes in the priority queue
        while (!pq.isEmpty()) {
            Map.Entry<Integer, Integer> current = pq.poll();
            int currentNode = current.getKey();
            int currentDist = current.getValue();

            // Skip if a shorter distance to the current node is already known
            if (currentDist > distances.get(currentNode)) {
                continue;
            }

            // Iterate through all neighbors of the current node
            for (Map.Entry<Integer, Integer> neighbor : adjList.get(currentNode).entrySet()) {
                int newDist = currentDist + neighbor.getValue();
                // If a shorter path to the neighbor is found, update and add to the queue
                if (newDist < distances.get(neighbor.getKey())) {
                    distances.put(neighbor.getKey(), newDist);
                    pq.offer(Map.entry(neighbor.getKey(), newDist));
                }
            }
        }

        // Find the maximum distance from the starting node to any other node
        int ans = Integer.MIN_VALUE;
        for (int distance : distances.values()) {
            if (distance == Integer.MAX_VALUE) return -1; // If any node is unreachable
            ans = Math.max(ans, distance);
        }
        return ans;
    }
}
