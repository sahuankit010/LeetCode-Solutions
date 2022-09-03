class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        int n = nums.size();
        int x = *min_element(nums.begin(), nums.end());
        unordered_map<int,int>mp;
        for(int i=x;i<=x+n-1;i++){
            mp[i]++;
        }
        for(int i=0;i<n;i++){
            mp[nums[i]]--;
        }
        for(auto i:mp){
            if(i.second>=1) return false;
        }
        return true;
    }
};