class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int preSum=0;
        int count=0;
        unordered_map<int,int>h;
        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];
            if(preSum==k) count++;
            if(h.find(preSum-k)!=h.end()) count+=h[preSum-k];
            h[preSum]++;
        }
        return count;
    }
};