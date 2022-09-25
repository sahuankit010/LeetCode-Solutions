class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n=accounts.size();
        int ans = -1;
        for(int i=0; i<n; i++){
            ans = max(ans, accumulate(accounts[i].begin(), accounts[i].end(), 0));
        }
        return ans;
    }
};