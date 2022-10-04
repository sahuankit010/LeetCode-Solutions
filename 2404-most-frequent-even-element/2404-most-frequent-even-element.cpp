class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(int z: nums){
            if(z%2==0){
                mp[z]++;
            }
        }
        int freq = 0;
        int mini = INT_MAX;
        for(auto x: mp){
            if(x.second>freq){
                mini = x.first;
                freq = x.second;
            } else if(x.second == freq){
                mini = min(mini, x.first);
            }
        }
        
        return mini==INT_MAX?-1:mini;
    }
};