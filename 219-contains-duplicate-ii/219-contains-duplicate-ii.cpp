class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // int count = 0;
        int n = nums.size();
        if(k==0) return false;
        unordered_set<int> s;
        for(int i=0;i<k&& i<n;i++){
            if(s.find(nums[i])!=s.end()) return true;
            s.insert(nums[i]);
        }
        
        for(int i=k;i<n;i++){
            if(s.find(nums[i])!=s.end()) return true;
            s.erase(nums[i-k]);
            s.insert(nums[i]);
        }
        
        return false;
    }
};