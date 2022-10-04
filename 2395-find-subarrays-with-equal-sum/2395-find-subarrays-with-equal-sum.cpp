class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int>hs;
        int n=nums.size();
        
        int sum = nums[0];
        
        for(int i=1; i<n; i++){
            if(hs.find(sum+nums[i])!=hs.end()) return true;
            else {
                sum += nums[i];
                hs.insert(sum);
            }
            sum -= nums[i-1];
        }
        return false;
    }
};