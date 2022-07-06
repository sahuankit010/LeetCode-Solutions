class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int> ump;
        for(int x:nums) ump[x]++;
        
        for(auto x: ump){
            if(k>0 and ump.find(x.first+k)!=ump.end()) count++;
            else if(k==0 and x.second>1) count++;
        }
        return count;
    }
};