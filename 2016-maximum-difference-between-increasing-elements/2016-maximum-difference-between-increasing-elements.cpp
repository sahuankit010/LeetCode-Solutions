class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int diff = INT_MIN, n = nums.size();
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j])
                    diff = max(diff, nums[j]-nums[i]);
            }
        }
        
        return diff==INT_MIN || diff == 0? -1 : diff;
    }
};