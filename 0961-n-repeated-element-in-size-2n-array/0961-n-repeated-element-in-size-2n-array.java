class Solution {
    public int repeatedNTimes(int[] nums) {
        int n = nums.length / 2;

        Map<Integer, Integer> hashmap = new HashMap<>();

        for (int i : nums) {
            if (hashmap.containsKey(i)) {
                if (hashmap.get(i) == n - 1)
                    return i;
            }
            hashmap.put(i, hashmap.getOrDefault(i, 0) + 1);

        }

        // Iterator it = hashmap.entrySet().iterator();

        // while (it.hasNext()) {
        //     Map.Entry mapElement = (Map.Entry) it.next();
        //     System.out.println(mapElement.getKey() + " " + mapElement.getValue());
        // }
        return -1;
    }
}