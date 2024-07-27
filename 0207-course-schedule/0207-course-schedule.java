class Solution {
    /*
    1. Prepare an adjacency list.
    2. Declare a visited array to keep track of visited nodes.
    3. Perform a DFS and check for cycles by using the visited array.
    4. In the DFS function, mark the current node as visited.
    5. Recursively perform DFS for its neighbors and check for cycles.
    6. Cycle check: If DFS returns false and the neighbor is not fully explored, it indicates a cycle.
    7. Mark the node as fully explored once all its neighbors are processed.
    */
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        
        // Initialize adjacency list
        List<List<Integer>> adj = new ArrayList<>();

        for(int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }

        // Populate adjacency list with given prerequisites
        for(int i = 0; i < prerequisites.length; i++) {
            adj.get(prerequisites[i][1]).add(prerequisites[i][0]);
        }

        // Initialize visited array with 0 (unvisited)
        int[] visited = new int[numCourses]; 

        // Iterate through each course
        for(int i = 0; i < numCourses; i++) {
            // If the course is not visited and there is a cycle, return false
            if(visited[i] == 0 && dfs(adj, visited, i)) return false;
        }

        // If no cycles are detected, return true
        return true;
    }

    private boolean dfs(List<List<Integer>> adj, int[] visited, int curr) {
        // Mark the current node as visiting (1)
        visited[curr] = 1;

        // Iterate through all the neighbors of the current node
        for(int neigh : adj.get(curr)) {
            // If the neighbor is unvisited, perform DFS on the neighbor
            if(visited[neigh] == 0) {
                if(dfs(adj, visited, neigh)) return true;
            } 
            // If the neighbor is still being visited, a cycle is detected
            else if(visited[neigh] == 1) return true;
        }

        // Mark the current node as fully explored (2)
        visited[curr] = 2;
        return false;
    }
}
