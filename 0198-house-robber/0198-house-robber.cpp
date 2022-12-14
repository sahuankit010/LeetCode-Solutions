class Solution {
public:
//     int robFunction(int i, vector<int>nums, vector<int> &memo){
//         if(i>=nums.size()) return 0;
        
//         if(memo[i]!=-1){
//             return memo[i];
//         }
        
//         int ans = max(robFunction(i+1, nums, memo), robFunction(i+2, nums, memo)+nums[i]);
//         memo[i]=ans;
//         return  ans;
//     }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>dp(n+1,0);
        
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=1; i<n; i++)
            dp[i+1] = max(dp[i-1]+nums[i], dp[i]);
        return dp[n];
        // return  robFunction(0, nums, memo);
    }
};