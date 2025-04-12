class Solution {
    public void setZeroes(int[][] matrix) {
        // Flags to check if the first row and the first column need to be set to zero
        boolean row = false, col = false;
        int m = matrix.length; // Number of rows in the matrix
        int n = matrix[0].length; // Number of columns in the matrix

        // First pass: determine which rows and columns need to be zeroed
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    // Set the first element of the respective row and column to 0
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                    
                    // If it's the first row, set the row flag
                    if (i == 0) row = true;
                    
                    // If it's the first column, set the column flag
                    if (j == 0) col = true;
                }
            }
        }

        // Second pass: use the marks in the first row and column to set elements to 0
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0; // Set the element to 0 if marked by the first row/column
                }
            }
        }

        // Zero out the first row if needed
        if (row) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Zero out the first column if needed
        if (col) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
}
