class Solution {
public:
    vector<vector<int>> memo;

    int findTargetSumWaysUtil(vector<int>& nums, int target, int idx) {
        if (idx == 0) {
            if (target == 0 && nums[idx] == 0)
                return 2;
            if (target == 0 || nums[idx] == target)
                return 1;
            return 0;
        }

        if(memo[idx][target] != -1) return memo[idx][target];

        int notTake = findTargetSumWaysUtil(nums, target, idx - 1);

        int take = 0;

        if(nums[idx] <= target){
            take =  findTargetSumWaysUtil(nums, target-nums[idx], idx-1);
        }

        return memo[idx][target] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if ((sum - target) < 0 || (sum - target) % 2 != 0)
            return 0;

        int s2 = (sum - target) / 2;
        int n = nums.size();
        memo.resize(n+1, vector<int>(s2+1, -1));

        return findTargetSumWaysUtil(nums, s2, nums.size() - 1);
    }
};