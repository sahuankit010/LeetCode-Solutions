class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<int>ans(2,0);
        
        for(auto x:mp){
            ans[0]+= x.second%2;
            ans[1]+=x.second/2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};