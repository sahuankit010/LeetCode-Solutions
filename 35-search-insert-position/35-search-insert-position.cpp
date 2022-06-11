class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        if(nums.size()==1){
            if(nums[0]>=target) return 0;
            return 1;
        }
        while(low<high){
            if(nums[low]==target){
                return low;
            }
            if(nums[high]==target) return high;
            if(nums[low]<target) low++;
            if(nums[high]>target) high--;
            if(nums[high]<target) return high+1;
            // if(nums[low]>target and nums[high]<target) 
        }
        
        return high;
    }
};