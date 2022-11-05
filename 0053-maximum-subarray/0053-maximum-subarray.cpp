class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxEnding = nums[0];
        int res = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            maxEnding = max(nums[i],maxEnding + nums[i]);
            res = max(res, maxEnding);
        }
        
        return res;
    }
};