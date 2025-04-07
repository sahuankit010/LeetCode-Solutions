class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);

        List<List<Integer>> ans = new ArrayList<>();

        for(int i=0; i<n-1; i++){

            if(i>0 && nums[i] == nums[i-1]) continue;

            int left = i+1, right = n-1;
            
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0){
                    ans.add(new ArrayList<>(Arrays.asList(nums[i], nums[left], nums[right])));

                    while(left < right && nums[left] == nums[left + 1]){
                        left++;
                    }

                    while(right > left && nums[right] == nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                } else if(sum < 0){
                    left++;
                } else{
                    right--;
                }
            }

            
        }

        return ans;
    }
}