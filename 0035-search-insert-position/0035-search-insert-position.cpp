class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n == 1){
            if(target>nums[0]) return 1;
            return 0;
        }
        int ans = -1;
        int l = 0, r = n-1;
        
        while(l <= r){
            int mid = l +(r-l)/2;
            
            if(nums[mid] == target) return mid;
            
            else if(nums[mid]>target){
                ans = mid;
                r = mid - 1;
            } else{
                l = mid + 1;
            }
        }
        
       return ans == -1?  n: ans;
    }
};