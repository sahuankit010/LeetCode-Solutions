class Solution {
public:
    int kadane(vector<int> nums, int n){
        
        int res = nums[0];
        int maxEnding = res;
        for(int i=1;i<n; i++){
            maxEnding = max(nums[i], nums[i]+maxEnding);
            res = max(res, maxEnding);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maximumNormal = kadane(nums,n);
        cout<<maximumNormal<<endl;
        if(maximumNormal<0) return maximumNormal;
        
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            nums[i]  = -1 * nums[i];
        }
        int maxCircular = sum + kadane(nums, n);
        
        return max(maxCircular, maximumNormal);
    }
    
};