class Solution {
public:
    int recur(int index, int amount, vector<int> &coins, int n, vector<vector<int>> &dp){
        if(amount==0) return 1;
        
        if(index>=n || amount<0) return 0;
        if(dp[amount][index]!=-1) return dp[amount][index];
        if(coins[index]>amount){
            return dp[amount][index] = recur(index+1, amount, coins, n, dp); 
        }
        return dp[amount][index] = recur(index, amount-coins[index], coins, n, dp)+
            recur(index+1, amount, coins, n, dp); 
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size(),-1));
        return recur(0, amount, coins, coins.size(), dp);
    }
};