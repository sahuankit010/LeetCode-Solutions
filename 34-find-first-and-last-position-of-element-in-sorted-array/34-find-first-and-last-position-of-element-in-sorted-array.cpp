class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int x) {
        
        int first=-1, last=-1;
        
        int low=0, high = nums.size()-1;
        
        while(low<=high){
            
            int mid = (low + high) / 2;
         
            if (nums[mid] > x)
                high = mid - 1;
            else if (nums[mid] < x)
                low = mid + 1;
            else {
                first = mid;
                high = mid - 1;
                }
            }
        low = 0;
        high = nums.size()-1;
        
        while(low<=high){
             int mid = (low + high) / 2;
         
            if (nums[mid] > x)
                high = mid - 1;
            else if (nums[mid] < x)
                low = mid + 1;

            else{
                last = mid;
                low = mid + 1;
            }
        }
        
        return {first,last};
    }
};