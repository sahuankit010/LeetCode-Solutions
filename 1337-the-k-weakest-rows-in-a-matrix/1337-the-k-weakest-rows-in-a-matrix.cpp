class Solution {
public:

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n= mat[0].size();
        vector<pair<int, int>> store(m);
        for(int i=0; i<m; i++){
            store[i] = {accumulate(begin(mat[i]), end(mat[i]), 0),i};
            
             // = {count1,i};
        }
        
        sort(begin(store), end(store));
        
        vector<int> ans(k);
        
        for(int i=0; i<k; i++)
            ans[i] = store[i].second;
        
        return ans;
    }
};