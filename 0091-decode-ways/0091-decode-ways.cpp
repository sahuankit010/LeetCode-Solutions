class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;

        int n = s.size();
        vector<int> dp(n + 1, 0); // DP array to store the number of ways to decode up to each position
        dp[0] = 1; // Base case: there's one way to decode an empty string

        // First character is valid if it isn't '0' since '0' doesn't map to any letter
        dp[1] = (s[0] != '0') ? 1 : 0;

        for (int i = 2; i <= n; i++) {
            // Check if the single digit number is valid (1-9)
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }

            // Check if the two digit number is valid (10-26)
            int two_digit = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if (two_digit >= 10 && two_digit <= 26) {
                dp[i] += dp[i-2];
            }
        }

        return dp[n];
    }
};
