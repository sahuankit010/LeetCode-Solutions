class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int low = 0, high = n-1;
        
        while(low<high){
            int mid  = low + (high-low)/2;
            bool halvesEven = (high-mid) % 2 == 0;
            
            if(nums[mid] == nums[mid+1]){
                if(halvesEven) low = mid + 2;
                else high = mid - 1;
            } else if(nums[mid] == nums[mid - 1]){
                if(!halvesEven) low = mid + 1;
                else high = mid - 2;
            } else return nums[mid];
        }
        
        return nums[low];
    }
};