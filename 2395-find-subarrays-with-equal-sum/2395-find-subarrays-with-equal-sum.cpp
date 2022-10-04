class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int>hs;
        int n=nums.size();
        
        int sum = nums[0];
        
        for(int i=1; i<n; i++){
            sum += nums[i];
            if(hs.find(sum)!=hs.end()) return true;
            else hs.insert(sum);
            sum -= nums[i-1];
        }
        return false;
    }
};