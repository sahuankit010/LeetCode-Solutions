class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;

        int[] prefixMin = new int[n];

        int[] suffixMax = new int[n];

        prefixMin[0] = prices[0];

        suffixMax[n-1] = prices[n-1];

        for(int i=1; i<n; i++){
            prefixMin[i] = Math.min(prefixMin[i-1], prices[i]);
        }

        for(int i=n-2; i>=0; i--){
            suffixMax[i] = Math.max(suffixMax[i+1], prices[i]);
        }

        int ans = 0;

        for(int i=0; i<n; i++){
            ans = Math.max(ans, suffixMax[i]-prefixMin[i]);
        }

        return ans;
    }
}