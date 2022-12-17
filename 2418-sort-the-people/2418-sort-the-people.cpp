class Solution {
public:
    static bool cmp(pair<int,string>p1, pair<int,string>p2){
        return p1.first>p2.first;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> vec;
        int n=names.size();
        for(int i=0; i<n; i++)
            vec.push_back({heights[i],names[i]});
        
        sort(vec.begin(), vec.end(), cmp);
        vector<string> ans;
        for(int i=0; i<n; i++)
            ans.push_back(vec[i].second);
        return ans;
    }
};