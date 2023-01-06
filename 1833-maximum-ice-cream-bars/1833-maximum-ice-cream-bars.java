class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        int i=0, n=costs.length;
        int ans = 0;
        while(coins>=0 && i<n){
            if(coins>=costs[i]){
                coins -= costs[i];
                i++;
                ans++;
            } else break;
        }
        return ans;
    }
}