class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        
        int sum = 0;
        for(int i: nums)
            sum += i;

        int lsum = 0;
        for(int i=0; i<n; i++){
            sum -= nums[i];
            if(sum == lsum) return i;
            lsum += nums[i];
        }
        return -1;
    }
}