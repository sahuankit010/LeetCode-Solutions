class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        sort(begin(nums), end(nums));
        int i=0, n = nums.size();
        for(; i<n-1; i+=2){
            if(nums[i+1]!=nums[i]) return nums[i];
        }
        if(i==n-1) return nums[n-1];
        return -1;
    }
};