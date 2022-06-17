class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int prefixSum = nums[0];
        int mini = INT_MAX;
        bool positive=false;
        if(prefixSum<1) positive = true;
        for(int i = 1; i<nums.size(); i++){
            mini=min(prefixSum,mini);
            prefixSum+=nums[i];
            if(prefixSum<1) positive = true;
        }
        mini = min(mini,prefixSum);
        if(prefixSum<1) positive = true;
       return (!positive)? 1 : 1-mini;
    }
};