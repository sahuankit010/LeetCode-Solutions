class Solution {
    int solve(int []dp, int n, int i){
        if(i==n) return 1;
        if(i>n) return 0;
        if(dp[i]!=0) return dp[i];
        return dp[i] = solve(dp, n, i+1) + solve(dp, n, i+2);
    }
    public int climbStairs(int n) {

        int dp[] = new int[n+1];
        
        return solve(dp, n, 0);
    }
}