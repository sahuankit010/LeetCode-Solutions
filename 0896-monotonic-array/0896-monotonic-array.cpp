class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increase = true, decrease = true;
        int n=nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i+1]>nums[i]){
                decrease = false;
                break;
            }
        }
        
        for(int i=0; i<n-1; i++){
            if(nums[i+1]<nums[i]){
                increase = false;
                break;
            }
        }
        
        return increase || decrease;
    }
};