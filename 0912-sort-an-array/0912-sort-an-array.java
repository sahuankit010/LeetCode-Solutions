class Solution {
    public int[] sortArray(int[] nums) {
        mergeSort(nums, 0, nums.length-1);
        return nums;
    }

    private void mergeSort(int[] nums, int left, int right){
        if(left < right){
            int mid = left + (right-left)/2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid+1, right);
            merge(nums, left, mid, right);
        }
    }

    private void merge(int[] nums, int left, int mid, int right){

        List<Integer> temp = new ArrayList<>();

        int low = left;

        int high = mid + 1;

        while(low <= mid && high <= right){
            if(nums[low] <= nums[high]) {
                temp.add(nums[low]);
                low++;
            } else{
                temp.add(nums[high]);
                high++;
            }
        }

        while(low <= mid){
            temp.add(nums[low]);
            low++;
        }

        while(high <= right){
            temp.add(nums[high]);
            high++;
        }

        for(int i=left; i<=right; i++){
            nums[i] = temp.get(i - left);
        }
    }
}