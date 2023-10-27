class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int left = 0, right, zeros = 0, ans = 0;

        for (right = 0; right < n; right++) {
            if (nums[right] == 0){
                zeros++;
                }
            if (zeros > 1 && nums[left++] == 0){
                zeros--;
                }
            ans = max(ans, right - left);
        }
        return ans; 
    }
};