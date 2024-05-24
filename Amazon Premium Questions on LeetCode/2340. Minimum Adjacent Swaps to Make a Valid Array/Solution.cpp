//
// Created by Ankit Sahu on 5/24/24.
//

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return 0;

        int largest = *max_element(begin(nums), end(nums));

        int smallest = *min_element(begin(nums), end(nums));

        int largest_idx, smallest_idx;

        for(int i=0; i<n; i++){
            if(smallest == nums[i]){
                smallest_idx = i;
                break;
            }
        }

        for(int i = n-1; i>=0; i--){
            if(largest == nums[i]){
                largest_idx = i;
                break;
            }
        }

        if(smallest_idx >= largest_idx){
            return n-largest_idx-1+smallest_idx-1;
        }

        return n-largest_idx-1+smallest_idx;
    }
};