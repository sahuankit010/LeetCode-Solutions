class Solution {
public:
    int convert(string &str){
        return (stoi(str.substr(0,2)) * 60) + stoi(str.substr(3,2));
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> store;
        for(string &s: timePoints)
            store.push_back(convert(s));
        sort(begin(store), end(store));
        
        int ans = INT_MAX;
        int n = store.size();
        for(int i=0; i<n-1; i++){
            int diff = store[i+1]-store[i];
            diff = min(diff, 24*60 - diff);
            ans = min(ans, diff);
        }
        int diff = store[n-1] - store[0];
        diff = min(diff, 24*60 - diff);
        ans = min(ans, diff);
        
        return ans;
    }
};