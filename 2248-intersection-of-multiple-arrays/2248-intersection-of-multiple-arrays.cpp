class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> mp;
        vector<int>ans;
        
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                mp[nums[i][j]]++;
            }
        }
        int n=nums.size();
        for(auto x: mp){
            if(x.second==n){
                ans.push_back(x.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};