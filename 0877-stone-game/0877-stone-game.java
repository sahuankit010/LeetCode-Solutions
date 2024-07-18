class Solution {
    // Memoization array to store intermediate results
    int[][] memo = new int[501][501];

    // Constructor to initialize the memoization array
    Solution() {
        // Fill the memo array with -1 to indicate uncalculated states
        for(int i = 0; i < 501; i++) {
            Arrays.fill(memo[i], -1);
        }
    }

    // Main method to determine if the first player can win the stone game
    public boolean stoneGame(int[] piles) {
        // Calculate the total sum of all piles
        int totalSum = Arrays.stream(piles).sum();

        // Calculate the maximum score the first player can achieve
        int s1 = rec(piles, 0, piles.length - 1);

        // The first player wins if their score is more than half the total sum
        return (totalSum - s1) < s1;
    }

    // Recursive helper method to calculate the maximum score for the current player
    private int rec(int[] piles, int left, int right) {
        // Base case: if no more piles to pick, return 0
        if(left >= right) return 0;

        // Return the memoized result if it exists
        if(memo[left][right] != -1) return memo[left][right];

        // Choose the better option between picking the leftmost or rightmost pile
        if(piles[left] >= piles[right]) {
            // Pick the leftmost pile and recursively calculate for the remaining piles
            return memo[left][right] = piles[left] + rec(piles, left + 1, right);
        } else {
            // Pick the rightmost pile and recursively calculate for the remaining piles
            return memo[left][right] = piles[right] + rec(piles, left, right - 1);
        }
    }
}
/*
Here's a brief explanation of the code:

Initialization:
The memo array is initialized with -1 to indicate that no values have been computed yet.

Main Method (stoneGame):
Calculates the total sum of piles and the maximum score the first player can achieve.
The game is won by the first player if their score is more than half of the total sum.

Recursive Method (rec): 
Determines the best possible score for the current player by 
considering whether to take the leftmost or rightmost pile, using memoization to store 
and reuse previously calculated results.
*/