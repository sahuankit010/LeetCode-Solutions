class Solution {
    public int numberOfSubarrays(int[] nums, int k) {

        int n = nums.length, ans = 0;

        Map<Integer, Integer> hashmap = new HashMap<>();

        hashmap.put(0, 1);

        int prefixSum = 0;

        for(int i=0; i<n; i++){
            prefixSum += (nums[i] % 2 == 1)? 1 : 0;

            if(hashmap.containsKey(prefixSum-k)){
                ans += hashmap.get(prefixSum-k);
            } 

            hashmap.put(prefixSum, hashmap.getOrDefault(prefixSum, 0) + 1);
        }   

        return ans;
    }
}