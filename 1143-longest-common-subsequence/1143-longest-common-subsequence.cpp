class Solution {
public:
//     int memo[1001][1001];
//     int lcs(string s1, string s2, int m, int n){
//        if(memo[m][n]!=-1){
//            return memo[m][n];
//        }
//         if(m==0 || n==0) memo[m][n] = 0;
//         else{
//             if(s1[m-1]==s2[n-1]){
//                 memo[m][n] = 1 + lcs(s1,s2, m-1, n-1);
//             } else{
//                 memo[m][n] = max(lcs(s1,s2,m,n-1), lcs(s1,s2, m-1,n));
//             }
//         }
        
//         return memo[m][n];
//     }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        int dp[m+1][n+1];
        
        for(int i=0; i<=m; i++){
            dp[i][0] = 0;
        }
        for(int j=0; j<=n; j++){
            dp[0][j]=0;
        }
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                dp[i][j] = (text1[i-1]==text2[j-1])? 1 + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};