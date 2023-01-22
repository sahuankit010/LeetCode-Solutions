class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int ans = 0;
        int n=nums.size();
        
        unordered_map<string, int> mp;
        
        for(string str: nums){
            mp[str]++;
        }
        
        for(string &str: nums){
            int prefixLength = str.length();
            if(target.substr(0, prefixLength) == str){
                string suff = target.substr(prefixLength);
                if(mp.find(suff)!=mp.end()){
                    ans += str == suff? mp[suff]-1: mp[suff];
                }
            }
        }
        
        return ans;
    }
};