class Solution {
public:
    static bool cmp(pair<char,int> p1, pair<char,int> p2){
        return p1.second>p2.second;
    }
    string frequencySort(string s) {
        map<char,int>hm;
        for(char c: s) hm[c]++;
        vector<pair<char,int>> vec;
        for(auto x: hm) vec.push_back({x.first,x.second});
        sort(vec.begin(),vec.end(),cmp);
        string ans;
        for(auto x: vec)
            for(int i=0;i<x.second;i++) 
                ans+=x.first;
        
        return ans;
    }
};