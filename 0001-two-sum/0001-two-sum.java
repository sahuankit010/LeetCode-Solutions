class Solution {
    static class Pair{
        int first;
        int second;

        Pair(int x, int y){
            this.first = x;
            this.second = y;
        }
    }
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;

        Map<Integer, Integer> map = new HashMap<>();

        for(int i = 0; i<n; i++){
            if(map.containsKey(target-nums[i])){
                return new int[]{i, map.get(target-nums[i])};
            } else{
                map.put(nums[i], i);
            }
        }

        // Pair[] temp  = new Pair[n];

        // for(int i=0; i<n; i++){
        //     temp[i] = new Pair(nums[i], i);
        // }

        // Arrays.sort(temp, (a, b) -> {
        //     if(a.first == b.first){
        //         return a.second -b.second;
        //     }
        //     return a.first-b.first;
        // });

        // int l = 0, r = n-1;

        // while(l < r){
        //     int sum = temp[l].first + temp[r].first;
        //     if(sum == target) return new int[] {temp[l].second, temp[r].second};
        //     else if(sum < target) l++;
        //     else r--;
        // }
        
        return new int[] {};
    }
}