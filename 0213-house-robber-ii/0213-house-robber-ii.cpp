class Solution {
public:
    int robFunction(vector<int> nums){
        int n=nums.size();
        vector<int>dp(n);
        
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);
        
        for(int i=2; i<n; i++){
            dp[i]=max(dp[i-1], nums[i]+dp[i-2]);
        }
        
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        // vector<int>memo1(100, -1), memo2(100,-1);
        vector<int>temp1(nums.begin(), nums.end()-1);
        vector<int>temp2(nums.begin()+1, nums.end());
        
        return max(robFunction(temp1), robFunction(temp2));
    }
};