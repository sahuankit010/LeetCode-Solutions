class Solution {
public:
    long long int solve(vector<int> &dp, vector<int> &nums, int curr, int des){
        if(curr==des) return 0;
        if(dp[curr]!=-1) return dp[curr];
        long long int tmp = INT_MAX;
        for(int i=1; i<= nums[curr]; i++){
            if(i+curr>des) break;
            
            tmp = min(tmp, 1 + solve(dp, nums, curr+i, des));
        }
        return dp[curr] = tmp;
    }
    int jump(vector<int>& nums) {
        int n =  nums.size();
        vector<int> dp(n,-1);
        return solve(dp, nums, 0, n-1);
    }
};