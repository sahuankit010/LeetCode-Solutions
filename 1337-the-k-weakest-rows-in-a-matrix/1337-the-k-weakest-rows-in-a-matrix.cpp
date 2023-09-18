class Solution {
public:
    static bool comp(pair<int, int> &p1, pair<int, int> &p2){
        if(p1.second < p2.second) return true;
        return p1.second == p2.second? p1.first <= p2.first : false;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n= mat[0].size();
        vector<pair<int, int>> store(m);
        for(int i=0; i<m; i++){
            int count1 = 0;
            for(int j=0; j<n; j++){
                if(mat[i][j]) count1++;
            }
            store[i] = {i, count1};
        }
        
        sort(begin(store), end(store), comp);
        
        vector<int> ans(k);
        
        for(int i=0; i<k; i++)
            ans[i] = store[i].first;
        
        return ans;
    }
};