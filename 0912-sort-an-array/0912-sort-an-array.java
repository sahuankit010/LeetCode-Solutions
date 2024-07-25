class Solution {
    // Method to sort an array using merge sort
    public int[] sortArray(int[] nums) {
        // Calling the mergeSort method to sort the array
        mergeSort(nums, 0, nums.length - 1);
        return nums; // Returning the sorted array
    }

    // Recursive method to divide the array into subarrays and sort them
    private void mergeSort(int[] nums, int left, int right) {
        if (left < right) {
            // Calculating the midpoint of the current array segment
            int mid = left + (right - left) / 2;
            // Recursively sorting the left half
            mergeSort(nums, left, mid);
            // Recursively sorting the right half
            mergeSort(nums, mid + 1, right);
            // Merging the two sorted halves
            merge(nums, left, mid, right);
        }
    }

    // Method to merge two sorted subarrays into a single sorted array
    private void merge(int[] nums, int left, int mid, int right) {
        // Temporary list to store the merged result
        List<Integer> temp = new ArrayList<>();

        // Pointers for the left and right subarrays
        int low = left;
        int high = mid + 1;

        // Merge the two subarrays into the temporary list
        while (low <= mid && high <= right) {
            if (nums[low] <= nums[high]) {
                temp.add(nums[low]);
                low++;
            } else {
                temp.add(nums[high]);
                high++;
            }
        }

        // Copy any remaining elements from the left subarray
        while (low <= mid) {
            temp.add(nums[low]);
            low++;
        }

        // Copy any remaining elements from the right subarray
        while (high <= right) {
            temp.add(nums[high]);
            high++;
        }

        // Copy the merged result back into the original array
        for (int i = left; i <= right; i++) {
            nums[i] = temp.get(i - left);
        }
    }
}
