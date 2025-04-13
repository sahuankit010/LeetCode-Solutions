class Solution {
    int n;

    int max = Integer.MAX_VALUE-1;
    int [][]memo;
    public int coinChange(int[] coins, int amount) {
        n = coins.length-1;
        memo = new int[n+1][amount+1];

        for(int i=0; i<n+1; i++){
            Arrays.fill(memo[i], -1);
        }
        int ans =  rec(coins, 0, amount);
        return ans == max? -1 : ans;
    }

    private int rec(int[] coins, int idx, int amount){
        if (idx == n){
            if(amount % coins[idx] == 0) return amount/coins[idx];
            return max;
        }

        if(memo[idx][amount] != -1) return memo[idx][amount];

        int notTake = rec(coins, idx+1,amount);

        int take = max;

        if(coins[idx] <= amount){
            take = 1 + rec(coins, idx, amount - coins[idx]);
        }

        return memo[idx][amount] = Math.min(notTake, take);
    }
}