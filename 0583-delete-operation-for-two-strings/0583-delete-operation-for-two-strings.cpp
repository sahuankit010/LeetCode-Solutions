class Solution {
public:
    int f(string &word1, string &word2, int n1, int n2, vector<vector<int>> &memo){

        if(n1==0) return n2;
        if(n2==0) return n1;

        if(memo[n1][n2]!=-1) return memo[n1][n2];

        if(word1[n1-1] == word2[n2-1]) return f(word1, word2, n1-1, n2-1, memo);

        else {
            int insertion = f(word1, word2, n1, n2 - 1, memo);
            int deletion = f(word1, word2, n1 - 1, n2, memo);
            // int substitution = f(word1, word2, n1 - 1, n2 - 1, memo);
            return memo[n1][n2] = 1 + min(insertion, deletion);
        }
        // return 1 + min(f(word1, word2, n1-1, n2), min(f(word1, word2, n1, n2-1), f(word1, word2, n1-1, n2-1)));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        // vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));
        vector<vector<int>> memo(n1+1, vector<int> (n2+1, -1));

        return f(word1, word2, n1, n2, memo);

        // for(int i=0; i<n1+1; i++)
        // dp[i][0] = i;

        // for(int i=0; i<n2+1; i++)
        // dp[0][i] = i;

        // for(int i=1; i<n1+1; i++){
        //     for(int j=1; j<n2+1; j++){
        //         if(word1[i-1]==word2[j-1])
        //         dp[i][j] = dp[i-1][j-1];
        //         else{
        //             dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
        //         }
        //     }
        // }
        // return dp[n1][n2];
    }
};