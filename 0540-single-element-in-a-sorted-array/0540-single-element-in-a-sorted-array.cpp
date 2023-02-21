class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i=0; i<n-1;){
            if(nums[i]!=nums[i+1]) return nums[i];
            i += 2;
        }
        return nums[n-1];
    }
};