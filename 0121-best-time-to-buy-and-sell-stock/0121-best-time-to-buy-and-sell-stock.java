class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0;
        int n = prices.length;
        int leftMin[] = new int[n], rightMax[] = new int[n];
        leftMin[0] = prices[0];
        for(int i = 1; i<n; i++){
            leftMin[i] = Math.min(leftMin[i-1], prices[i]);
        }
        rightMax[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--){
            rightMax[i] = Math.max(rightMax[i+1], prices[i]);
        }
        
        for(int i=0; i<n; i++){
            ans = Math.max(ans, rightMax[i]-leftMin[i]);
        }
        return ans;
    }
}