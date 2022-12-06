class Solution {
public:
//     int solve(vector<vector<int>> grid, int row, int col, vector<vector<int>> &dp){
        
//         if(row==0 && col==0) return grid[row][col];
//         if(dp[row][col]!=0) return dp[row][col];
//         if(row==0 && col!=0) return dp[row][col] = grid[row][col] + solve(grid, row, col-1, dp);
//         if(col==0 && row!=0) return dp[row][col] = grid[row][col] + solve(grid, row-1, col, dp);
//         return dp[row][col] = grid[row][col] + min(solve(grid, row-1, col, dp), solve(grid, row, col-1, dp));
//     }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>dp(n, vector<int>(m,0));
        dp[0][0]=grid[0][0];
        
        for(int i=1;i<n;i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int j=1;j<m;j++)
            dp[0][j] = dp[0][j-1] + grid[0][j];
         for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
        return dp[n-1][m-1];
    }
    

//     int minPathSum(vector<vector<int>> &grid){
//         int n=grid.size();
//         int m=grid[0].size();
//         vector<vector<int> dp(n, vector<int>(m,0));
        
//         return solve(grid, n-1,m-1);
//     }
};