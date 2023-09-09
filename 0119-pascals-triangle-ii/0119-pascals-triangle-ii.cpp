class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> ans;
        
        for(int i=0; i<=n; i++){
            vector<int> curr(i+1);
            
            curr[0] = 1;
            curr[i] = 1;
            
            for(int j=1; j<i; j++){
                curr[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            
            ans.push_back(curr);
        }
        
        return ans[n];
    }
};