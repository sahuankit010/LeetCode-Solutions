class Solution {
public:
    // Depth-First Search (DFS) to mark connected components
    void dfs(vector<vector<int>> &matrix, int curr_row, int curr_col) {
        int m = matrix.size();       // Number of rows in the matrix
        int n = matrix[0].size();    // Number of columns in the matrix

        // Base cases for DFS to stop recursion
        if(curr_row < 0 || curr_row >= m || curr_col < 0 || curr_col >= n) return;  // Out of bounds
        if(matrix[curr_row][curr_col] == 1) return;  // Already visited or blocked cell

        // Mark the current cell as visited
        matrix[curr_row][curr_col] = 1;

        // Recursively visit all four adjacent cells (up, down, left, right)
        dfs(matrix, curr_row+1, curr_col);  // Down
        dfs(matrix, curr_row-1, curr_col);  // Up
        dfs(matrix, curr_row, curr_col+1);  // Right
        dfs(matrix, curr_row, curr_col-1);  // Left
    }

    // Main function to calculate the number of regions created by slashes
    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();       // Number of rows in the grid
        int cols = grid[0].size();    // Number of columns in the grid

        // Create an enlarged matrix to represent the grid, each cell in the grid is split into 3x3 cells
        vector<vector<int>> matrix(rows * 3, vector<int>(cols * 3));

        // Populate the matrix based on slashes in the grid
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '/') {
                    // Mark cells that are part of a '/' slash
                    matrix[i * 3][j * 3 + 2] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3] = 1;
                } else if(grid[i][j] == '\\') {
                    // Mark cells that are part of a '\' slash
                    matrix[i * 3][j * 3] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        int regions = 0;  // Initialize region count

        // Iterate over each cell in the matrix
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                // If the cell is unvisited (0), it's a new region
                if(matrix[i][j] == 0) {
                    // Perform DFS to mark the entire region
                    dfs(matrix, i, j);
                    regions++;  // Increment the region count
                }
            }
        }

        return regions;  // Return the total number of regions
    }
};
