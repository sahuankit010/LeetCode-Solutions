class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1) return 0;
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        int ans = INT_MAX;
        
        for(int i=0;i<n-k+1;i++){
            int maxi = INT_MIN, mini = INT_MAX;
            
            for(int j = i; j<i+k; j++){
                maxi = max(nums[j], maxi);
                mini = min(nums[j], mini);
            }
            
            ans = min(ans, maxi - mini);
        }
        
        return ans;
    }
};