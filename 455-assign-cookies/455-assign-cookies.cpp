class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.empty()) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int ans = 0;
        int j=0;
        for(int i=0;i<g.size();){
            if(g[i]<=s[j]){
                ans++;
                i++;
            } 
            if(j==s.size()-1) break;
            j++;
        }
        return ans;
    }
};