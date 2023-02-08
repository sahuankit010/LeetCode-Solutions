class Solution {
public:
//     long long int solve(vector<int> &dp, vector<int> &nums, int curr, int des){
//         if(curr==des) return 0;
//         if(dp[curr]!=-1) return dp[curr];
//         long long int tmp = INT_MAX;
//         for(int i=1; i<= nums[curr]; i++){
//             if(i+curr>des) break;
            
//             tmp = min(tmp, 1 + solve(dp, nums, curr+i, des));
//         }
//         return dp[curr] = tmp;
//     }
    int jump(vector<int>& nums) {
        int n =  nums.size();
        
        if(n==1) return 0;
        int jump = 1, currjump = nums[0], maxjump = nums[0];
        int i=1;
        while(i<n-1){
            maxjump = max(maxjump, i + nums[i]);
            
            if(i == currjump){
                jump++;
                currjump = maxjump;
            }
            i++;
        }
        return jump;
    }
};