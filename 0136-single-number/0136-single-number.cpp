class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hash;
        
        for(int i: nums) hash[i]++;
        
        for(auto &i: hash){
            if(i.second == 1) return i.first;
        }
        
        return -1;
    }
};