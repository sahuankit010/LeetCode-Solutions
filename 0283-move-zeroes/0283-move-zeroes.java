class Solution {
    public void moveZeroes(int[] nums) {
        int zeros = 0;
        int n = nums.length;
        for(int i = 0; i< n; i++){
            if(nums[i] == 0) zeros++;
        }
        int k= 0;
        for(int i = 0; i< n; i++){
            if(nums[i] != 0) nums[k++] = nums[i];
        }

        for(int i = k; i<zeros + k; i++){
            nums[i] = 0;
        }
    }
}