class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long left = 0; //
        long long right = 0; //
        long long res = 0;
        long long total = 0;
        int n = nums.size();
        
        while(right < n){
            total += nums[right];
            while((nums[right] * (right - left + 1)) > total + k){
                total -= nums[left]; 
                left += 1;
            }
            res = max(res, right-left+1);
            right += 1;
        }
        return res;
    }
};