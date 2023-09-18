class Solution {
public:
    int f(int i, int j, int m, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        if(i == m-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = triangle[i][j] + min(f(i+1, j, m, triangle, dp), f(i+1, j+1, m, triangle, dp));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        // return f(0, 0, m, triangle, dp);
        
        for(int i=0; i<triangle[m-1].size(); i++)
            dp[m-1][i] = triangle[m-1][i];
        
        for(int i=m-2; i>=0; i--){
            
            for(int j=i; j>=0; j--){
                
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
                
            }
        }
        
        return dp[0][0];
    }
};