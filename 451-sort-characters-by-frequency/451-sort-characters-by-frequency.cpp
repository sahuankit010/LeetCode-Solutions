class Solution {
public:
    static bool cmp(pair<char,long long> p1, pair<char,long long> p2){
        return p1.second>p2.second;
    }
    string frequencySort(string s) {
        map<char,long long>hm;
        for(char c: s) hm[c]++;
        vector<pair<char,long long>> vec;
        for(auto x: hm) vec.push_back({x.first,x.second});
        sort(vec.begin(),vec.end(),cmp);
        string ans;
        for(auto x: vec)
            for(long long i=0;i<x.second;i++) 
                ans+=x.first;
        
        return ans;
    }
};