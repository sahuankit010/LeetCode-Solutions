class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(arr);
        int n = arr.length;

        int diff = Integer.MAX_VALUE;

        for(int i = 0; i < n-1; i++){
            diff = Math.min(diff, arr[i+1] - arr[i]);
        }

        for(int i = 0; i< n - 1; i++){
            List<Integer> each = new ArrayList<>();
            if(arr[i+1] - arr[i] == diff){
                each.add(arr[i]);
                each.add(arr[i+1]);
            }
            if(each.size()>0) ans.add(each);
        }

        return ans;
    }
}