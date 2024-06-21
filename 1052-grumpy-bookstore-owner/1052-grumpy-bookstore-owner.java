class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int n = customers.length;

        int maxWindowSum = 0;

        int currWindowSum = 0;

        // Initial window calculation
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                currWindowSum += customers[i];
            }
        }

        maxWindowSum = currWindowSum;
        
        int left = 0, right = minutes - 1;

        // Sliding window to find max sum of unsatisfied customers that could be satisfied
        for (int i = minutes; i < n; i++) {
            if (grumpy[i] == 1) {
                currWindowSum += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                currWindowSum -= customers[i - minutes];
            }

            if (maxWindowSum < currWindowSum) {
                maxWindowSum = currWindowSum;
                left = i - minutes + 1;
                right = i;
            }
        }

        int ans = maxWindowSum;

        // Add customers who are always satisfied outside the special window
        for (int i = 0; i < left; i++) {
            if (grumpy[i] == 0)  ans += customers[i];
        }

        for (int i = right + 1; i < n; i++) {
            if (grumpy[i] == 0)  ans += customers[i];
        }

        // Additionally include customers within the optimal window who are always satisfied
        for (int i = left; i <= right; i++) {
            if (grumpy[i] == 0) {
                ans += customers[i];
            }
        }

        return ans;
    }
}
