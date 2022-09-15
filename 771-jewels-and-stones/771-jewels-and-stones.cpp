class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int>mp;
        
        for(char c: jewels) mp[c]++;
        
        int ans = 0;
        
        for(int i=0;i<stones.size(); i++){
            if(mp.find(stones[i])!=mp.end())
                ans++;
        }
        return ans;
    }
};