class Solution {
public:
    // i rows
    //j cols
    int recur(int rows, int cols,int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &memo){
        if(i>=rows || j<0 || j>=cols) return 1e9;

        if(i==rows-1) return matrix[i][j];
        
        if (memo[i][j]!=-INT_MIN) return memo[i][j];

        int down = matrix[i][j] + recur(rows, cols, i+1, j, matrix, memo);
        int leftDown = matrix[i][j] + recur(rows, cols, i+1, j-1, matrix, memo);
        int rightDown = matrix[i][j] + recur(rows, cols, i+1, j+1, matrix, memo);

        return memo[i][j]= min(down, min(leftDown, rightDown));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        // vector<vector<int>> memo(rows, vector<int>(rows, INT_MIN));
        
        // int ans = INT_MAX;
        // for(int j = 0; j<cols; j++){
        //     ans  = min(ans, recur(rows, cols, 0, j, matrix, memo));
        // }
        // return ans;
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        // Initialize the dp matrix with the values from the last row.
        for (int j = 0; j < cols; j++) {
            dp[rows - 1][j] = matrix[rows - 1][j];
        }

        // Start from the second-to-last row and move upwards.
        for (int i = rows - 2; i >= 0; i--) {
            for (int j = 0; j < cols; j++) {
                dp[i][j] = matrix[i][j] + min(
                    dp[i + 1][j], // Move directly down
                    min(j > 0 ? dp[i + 1][j - 1] : INT_MAX, // Move down and left
                        j < cols - 1 ? dp[i + 1][j + 1] : INT_MAX) // Move down and right
                );
            }
        }

        // The minimum falling path sum will be in the first row.
        int ans = INT_MAX;
        for (int j = 0; j < cols; j++) {
            ans = min(ans, dp[0][j]);
        }

        return ans;
    }
};