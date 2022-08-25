class Solution {
public:
    static bool cmp(pair<int,int> &p1, pair<int,int> &p2){
        if(p1.second<p2.second) return true;
        if(p1.second == p2.second) return p1.first>p2.first;
        return false;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>hm;
        for(int c: nums) 
            hm[c]++;
        vector<pair<int,int>> ans;
        for(auto x: hm) ans.push_back({x.first, x.second});
        
        sort(ans.begin(),ans.end(),cmp);
        vector<int>vec;
        
        for(auto x: ans) {
            for(int i=0;i<x.second;i++)
                vec.push_back(x.first);
            }
        return vec;
    }
};