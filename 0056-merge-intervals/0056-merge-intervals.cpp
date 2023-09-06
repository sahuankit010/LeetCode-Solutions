class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        vector<vector<int>> ans;
        
        sort(begin(interval), end(interval));
        
        int n = interval.size(), q = 0;
        ans.push_back(interval[0]);
        for(int i=1; i<n; i++){
            if(interval[i][0]<=ans[q][1]){
                ans[q][0] = min(ans[q][0], interval[i][0]);
                ans[q][1] = max(ans[q][1], interval[i][1]);
            } else{
                ans.push_back(interval[i]);
                q++;
            }
        }
        
        return ans;
    }
    
};