class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int mini = INT_MAX;
        int ans;
        
        for(int i=0; i<nums.size(); i++){
            if(mini>abs(nums[i]-0)){
                mini = abs(nums[i]-0);
                ans = i;
            }
        }
        
        return nums[ans];
    }
};