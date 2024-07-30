class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;

        // If there's only one child, they get one candy
        if (n == 1) return 1;

        // Initialize an array to store the number of candies each child will get
        int[] candies = new int[n];

        // Initially, give each child one candy
        Arrays.fill(candies, 1);

        // Traverse the ratings array from left to right
        for (int i = 1; i < n; i++) {
            // If the current child's rating is higher than the previous child's rating,
            // give the current child one more candy than the previous child
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }

        // Traverse the ratings array from right to left
        for (int i = n - 2; i >= 0; i--) {
            // If the current child's rating is higher than the next child's rating
            // and the current child doesn't have more candies than the next child,
            // give the current child one more candy than the next child
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
                candies[i] = candies[i + 1] + 1;
        }

        // Sum up the total candies and return
        return Arrays.stream(candies).sum();
    }
}
