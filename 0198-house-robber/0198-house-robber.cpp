class Solution {
public:
    int n;
    vector<int>memo;
    int rec(vector<int>& nums, int idx){
        if(idx >= n) return 0;
        if(idx == n-1 || idx == n-2) return nums[idx];
        if(memo[idx] != -1) return memo[idx];
        
        return memo[idx] = nums[idx] + max(rec(nums, idx+2), rec(nums, idx+3));
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n == 1) return nums[0];
        memo.resize(n+1, -1);
        int v1 = rec(nums, 0);
        memo.clear();
        memo.resize(n+1, -1);
        int v2 = rec(nums, 1);
        int ans = max(v1, v2);
        return ans;
    }
};