class Solution {
    public int maximumWealth(int[][] accounts) {
        int ans = 0;
        int n = accounts.length;
        
        for(int i=0; i<n; i++){
            int curr_row_sum = 0;
            int m = accounts[i].length;
            for(int j=0; j<m; j++){
                curr_row_sum += accounts[i][j];
            }
            ans = Math.max(curr_row_sum, ans);
        }
        return ans;
    }
}