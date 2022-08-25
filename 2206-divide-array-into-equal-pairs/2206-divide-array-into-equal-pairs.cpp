class Solution {
public:
    bool divideArray(vector<int>& nums) {
        if(nums.size()%2==1) return false;
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        
        for(auto x: mp){
            if(x.second%2!=0) return false;
        }
        return true;
    }
};