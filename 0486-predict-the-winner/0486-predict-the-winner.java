class Solution {
    // Memoization array to store intermediate results
    int[][] memo = new int[21][21];

    // Constructor to initialize the memoization array
    Solution() {
        // Fill the memo array with -1 to indicate uncalculated states
        for (int i = 0; i < 21; i++) {
            Arrays.fill(memo[i], -1);
        }
    }

    public boolean predictTheWinner(int[] nums) {
        // Calculate the total sum of all nums
        int totalSum = Arrays.stream(nums).sum();

        // Calculate the maximum score the first player can achieve
        int s1 = rec(nums, 0, nums.length - 1, totalSum);
        
        // The first player wins if their score is more than half the total sum
        return (totalSum - s1) <= s1;
    }

    // Recursive helper method to calculate the maximum score for the current player
    private int rec(int[] nums, int left, int right, int totalSum) {
        // Base case: if no more nums to pick, return 0
        if(left > right) return 0;

        // Return the memoized result if it exists
        if(memo[left][right] != -1) return memo[left][right];

        int leftS = nums[left] + Math.min(rec(nums, left + 2, right, totalSum), rec(nums, left + 1, right-1, totalSum));
        int rightS = nums[right] + Math.min(rec(nums, left + 1, right-1, totalSum), rec(nums, left, right-2, totalSum));

        return memo[left][right] = Math.max(leftS, rightS);
       
    }
}