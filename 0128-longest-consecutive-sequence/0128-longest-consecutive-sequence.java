class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums == null)
            return 0;
        
        int n = nums.length;
        
        if (n == 0)
            return 0;

        Set<Integer> hashset = new HashSet<>();
        for (int num : nums) {
            hashset.add(num);
        }
        int ans = 0;

        for (int i : hashset) {
            if (!hashset.contains(i-1)) {
                int curr = 1;

                while (hashset.contains(i + 1)) {
                    curr++;
                    i++;
                }

                ans = Math.max(ans, curr);
            }
        }

        return ans;
    }
}