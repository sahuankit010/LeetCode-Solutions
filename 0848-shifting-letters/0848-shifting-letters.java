class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        // Calculate the length of the input string
        final int n = s.length();
        
        // Initialize an array to store the cumulative sums of the shifts from right to left
        long[] suffixSum = new long[n];
        
        // Start by adding the last element of the shifts array to the last position in suffixSum
        suffixSum[n-1] = shifts[n-1];
        
        // Calculate the suffix sums for each position from the end to the beginning of the string
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = shifts[i] + suffixSum[i + 1];
        }
        
        // Initialize an empty string to build the result
        String ans = "";
        
        // Loop through each character of the string
        for (int i = 0; i < n; i++) {
            // Calculate the new character by shifting the current character by the amount in suffixSum
            long newChar = ((s.charAt(i) - 'a') + suffixSum[i]) % 26;
            // Append the shifted character to the result string
            ans += (char)(newChar + 'a'); 
        }
        
        // Return the final shifted string
        return ans;
    }
}
