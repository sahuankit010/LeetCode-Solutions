class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
        int sum = nums[0];
        for(int i=1; i<nums.size(); i++) {
            sum+=nums[i];
            ans.push_back(sum);
        }
           
        return ans;
    }
};