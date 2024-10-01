class Solution {
public:
    /*
    1. Sorting
    2. use a set
    */
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i=1; i<n; i++){
            if(nums[i-1] == nums[i]) return true;
        }

        return false;
    }
};