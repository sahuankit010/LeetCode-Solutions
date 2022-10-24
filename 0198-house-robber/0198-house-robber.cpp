class Solution {
public:
    int robFunction(int i, vector<int>nums, vector<int> &memo){
        if(i>=nums.size()) return 0;
        
        if(memo[i]!=-1){
            return memo[i];
        }
        
        int ans = max(robFunction(i+1, nums, memo), robFunction(i+2, nums, memo)+nums[i]);
        memo[i]=ans;
        return  ans;
    }
    int rob(vector<int>& nums) {
        vector<int>memo(101, -1);
        return  robFunction(0, nums, memo);
    }
};