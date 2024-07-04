class Solution {
    public int longestConsecutive(int[] arr) {
        int n = arr.length;
        if(n==0 || arr == null) return 0;

        int curr = 1;
        int ans = 1;

        int min = arr[0];
        int max = arr[0];

        TreeSet<Integer> set = new TreeSet<>();
        set.add(arr[0]);

        for(int i=1; i<n; i++){
           min = Math.min(min, arr[i]);
           max = Math.max(max, arr[i]);
           set.add(arr[i]);
        }
        
        int last = min;

        for(int i=min; i<=max; i = set.higher(i)){
            
            if(last == i-1){
                curr += 1;
            } else{
                curr = 1;
            }

            ans = Math.max(ans, curr);
            last = i;
            if(set.higher(i) == null) break;
        }

        return ans;
    }
}