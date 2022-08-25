class Solution {
public:
    static bool cmp(pair<int,int> &p1, pair<int,int> &p2){
        return p1.second>p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hm;
        for(int x: nums) hm[x]++;
        vector<pair<int,int>> vec;
        for(auto x: hm) vec.push_back({x.first, x.second});
        sort(vec.begin(),vec.end(),cmp);
        vector<int>ans;
        int j=0;
        for(int i = 0; i<k; i++)
            ans.push_back(vec[j++].first);
        return ans;
    }
};