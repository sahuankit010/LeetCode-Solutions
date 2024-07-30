class Solution {

    public int getMaximumGold(int[][] grid) {

        int m = grid.length; // Number of rows in the grid
        int n = grid[0].length; // Number of columns in the grid

        int ans = 0; // Variable to store the maximum gold collected
        
        for (int i = 0; i < m; i++) { // Iterate over each cell in the grid
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) // Start DFS only from cells that contain gold
                    ans = Math.max(ans, rec(grid, i, j)); // Update the maximum gold collected
            }
        }
        return ans; // Return the maximum gold collected
    }

    private int rec(int[][] grid, int i, int j) {

        int m = grid.length; // Number of rows in the grid
        int n = grid[0].length; // Number of columns in the grid

        // Check for boundary conditions and if the cell is empty or visited
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || grid[i][j] == 101) return 0;

        int curr = grid[i][j]; // Store the current cell's gold amount

        grid[i][j] = 101; // Mark the cell as visited by setting it to a special value

        // Recursively collect gold from all four possible directions
        int left = rec(grid, i, j - 1);
        int right = rec(grid, i, j + 1);
        int top = rec(grid, i - 1, j);
        int bottom = rec(grid, i + 1, j);

        grid[i][j] = curr; // Backtrack by resetting the cell to its original value

        // Return the total gold collected from the current cell and the maximum of all four directions
        return curr + Math.max(left, Math.max(right, Math.max(bottom, top)));
    }
}
