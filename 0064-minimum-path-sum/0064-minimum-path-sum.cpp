class Solution {
public:
    
//     int f(vector<vector<int>> &grid, int i, int j, int m ,int n, vector<vector<int>> &dp){
        
//         if(i== m-1 && j == n-1) return grid[i][j];
//         if(i>=m || j>=n) return INT_MAX;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         return dp[i][j] = grid[i][j] + min(f(grid, i+1, j, m, n, dp), f(grid, i, j+1, m, n, dp));
//     }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n));
        
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                else if(i==0) dp[i][j] = grid[i][j] + dp[i][j-1];
                else if(j==0) dp[i][j] = grid[i][j] + dp[i-1][j];
                // if(i==m-1 && j==n-1) dp[i][j] = 
                else dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
                    
            }
        }
        
        return dp[m-1][n-1];
    }
};