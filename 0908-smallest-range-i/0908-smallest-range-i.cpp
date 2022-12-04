class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxValue = *max_element(begin(nums), end(nums));
        int minValue = *min_element(begin(nums), end(nums));
        
        return max(0, maxValue-minValue-2*k);
    }
};